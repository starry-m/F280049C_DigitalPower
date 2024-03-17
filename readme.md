# 基于F280049C的数控电源

# 一、任务要求
本任务为自命题任务，预计达到的要求为
* 外接电源拓扑模块，组合成一个完整数控电源。
* 屏幕显示输入输出电压。
* 输出电压可调。

# 二、设计思路
 这一款LAUNCHXL-F280049C板卡是TI C2000系列中的一员，对于处理电源和电机这种快速环路控制非常高效。其内部的EPWM模块功能丰富，我这次设计就是打算使用其互补输出的EPWM，驱动拓扑电路实现数控电源。
 本次任务用到的外设有EPWM、ADC、I2C、SCIA、GPIO。
 EPWM驱动全桥，ADC测量输入输出电压电流，I2C驱动OLED SSD1306显示，SCIA交互，GPIO做状态显示。
 接口框图如下：
 ![](./pic/结构框图.png)


# 三、实现过程

## 1、开发环境的搭建
首先下载TI官方的IDE CCS，以及C2000 WARE SDK，实现快速开发。一般最好是导入一个示例，在此基础上再去修改，增加，实现自己想要的功能。

## 2、图形化配置syscfg
TI也与时俱进，推出了适配CCS上开发的图形界面，根据我这些天的使用，效果非常棒，驱动部分全都由此生成，还有一些组件库，如文件系统等，也可以支持。总的来说，这种图像化界面的驱动配置方式会越来越流行，降低我们开发的难度和门槛。

## 3、CMD文件的认识
对于单片机来说，内存块的设置，一般都有默认的设置，我们一般都不会去修改他。但是在DSP中，却多了一种CMD，内存配置文件，用来指定不同的数据text、data、BSS、stack等所存放的位置和大小。相比较起来灵活很多，但也带来了一些配置的麻烦。比如说我导入GPIO翻转的示例，想在上面加上屏幕显示，一下就显示我text段的内存分配不够。对于我们这种新手来说可能一下就蒙了。
但也会有好处，让我们对其底层的数据段和内存有更深入的认识。

## 4、EPWM的学习与配置
C2000的EPWM具有常用PWM外设都有的功能，如基本的定时，互补输出，死区设置，比较等。其中，他有一个我第一次遇到的功能，计数方式可配置成`up-down`模式，就是一个定时周期中，既有计数逐个增加还有计数逐个减少。一开始我并不知道这种模式有什么用处，直到我后面驱动MOS管时，查找资料才知道BUCK-BOOST电路中，ADC的采样时刻是用要求的，当其处于PWM的脉冲高电平的中间时，这时系统的电压和电流是比较稳定，完美的避过MOS管开关引起的震荡影响。
大概就是向我下面这样画的。
![](./pic/PWM计数.png)
我们在计数值为0时，此时处于高电平正中间，此处去触发ADC采样，得到最准确的值。
PWM频率和周期设置如下：
![](./pic/PWM频率.png)
此时PWM频率为`100Mhz /1 /1 /(500*2)=100khz` 。
然后配置成互补带死区模式
![](./pic/死区设置.png)
这样设置后，PWM通道B的比较值设置就会失效，完全由通道A决定，并且设置10个计数值的切换延迟（100ns）。
![](./pic/触发事件.png)
此外还可以设置多少个周期触发一次PWM中断，以及给ADC提供的触发源设置。如图是计数值为0时产生事件。
然后就只剩下引脚分配，就结束了。我们就只需要去实现PWM中断函数。

## 5、ADC的配置
280049的片内ADC是12位的，精度还可以。他一共有3个ADC：ADCA、ADCB、ADCC。其中只有ADCA和ADCB支持PWM的事件触发。ADC的重点在下面的 触发源选择。
![](./pic/ADC触发.png)
其他的就只是通道选择和参考源选择。

## 6、I2C的配置
在sdk中，我没看到有封装好的直接发送的函数，只能自己一步步组合起来。
![](./pic/I2C配置.png)
我用的是阻塞的方式传输，他这个中断的方式暂时还没搞明白。
对于SSD1306，我们只需要移植现成的驱动，然后修改底层接口就行。
```c
 void Write_IIC_Data(unsigned char IIC_Data)
{

    I2C_setDataCount(myI2C0_BASE,2);
    I2C_putData(myI2C0_BASE, 0x40);//ַ
    I2C_putData(myI2C0_BASE, IIC_Data);//

    I2C_setConfig(myI2C0_BASE, I2C_MASTER_SEND_MODE);//
    I2C_sendStartCondition(myI2C0_BASE);//
    I2C_sendStopCondition(myI2C0_BASE);//
    DEVICE_DELAY_US(Delay_MinTime);
}
 ```
## 7、SCIA串口的配置
串口这里基本一样
![](./pic/串口.png)
然后我们在中断中加入我们的电压设置,这里是基于示例改的
``` c
msg = "\r\n--F280048C-Digital Power--\n\0";
SCI_writeCharArray(SCIA_BASE, (uint16_t *)msg, 31);
msg = "\r\nyou can send 2 characters to set voltage,such as :“51” ->set:5.1V\n\0";
SCI_writeCharArray(SCIA_BASE, (uint16_t *)msg, 74);
//
// sciaRxISR - Read two characters from the RXBUF and echo them back.
//
__interrupt void INT_mySCI0_RX_ISR(void)
{
    uint16_t receivedChar1, receivedChar2;
    //
    // Enable the TXFF interrupt again.
    //
    SCI_enableInterrupt(SCIA_BASE, SCI_INT_TXFF);

    //
    // Read two characters from the FIFO.
    //
    receivedChar1 = SCI_readCharBlockingFIFO(SCIA_BASE);
    receivedChar2 = SCI_readCharBlockingFIFO(SCIA_BASE);

    //
    // Echo back the two characters.
    //
    msg = "  You sent: \0";
    SCI_writeCharArray(SCIA_BASE, (uint16_t *)msg, 13);
    SCI_writeCharBlockingFIFO(SCIA_BASE, receivedChar1);
    SCI_writeCharBlockingFIFO(SCIA_BASE, receivedChar2);
    vtarget = (receivedChar1 - '0') + (receivedChar2 - '0') / 10.0;
    //
    // Clear the SCI RXFF interrupt and acknowledge the PIE interrupt.
    //
    SCI_clearInterruptStatus(SCIA_BASE, SCI_INT_RXFF);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
}

```
## 8、PI控制器的配置
sysconfig中有提供直接使用的PID控制器，TI官方对其内部做了汇编加速处理。
![](./pic/PI控制器.png)
我这里还没有把控制参数调到最佳。

## 9、应用逻辑处理
首先是完善PWM中断处理,这里是在中断中读取ADC采样值和进行环路计算。可能会占用比较多的时间，因此会有把代码放RAM中运行的处理。
``` c
uint16_t Sample_Temp;
//
// epwm1ISR - ePWM 1 ISR
//
#pragma CODE_SECTION(INT_myEPWM0_ISR, "ramfuncs");
__interrupt void INT_myEPWM0_ISR(void)
{

    isr_counter++;
    if (isr_counter == 2000)
    {
        GPIO_togglePin(23);
        isr_counter = 0;
        time_flag = 1;
    }
    Sample_Temp = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER0);
    I_L_temp = (Sample_Temp * 3300.0 / 4096) * 0.00757575f;
    Sample_Temp = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER1);
    Vin_temp = (Sample_Temp * 3300.0 / 4096) * 0.011f;
    Sample_Temp = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER2);
    I_in_temp = (Sample_Temp * 3300.0 / 4096) * 0.00757575f - 12.49998f;

    Sample_Temp = ADC_readResult(ADCBRESULT_BASE, ADC_SOC_NUMBER0);
    Vout_temp = (Sample_Temp * 3300.0 / 4096) * 0.011f;

    Sample_Temp = ADC_readResult(ADCBRESULT_BASE, ADC_SOC_NUMBER1);
    I_out_temp = (Sample_Temp * 3300.0 / 4096) * 0.00757575f - 12.49998f;

    compBValue = (uint16_t)DCL_runPI_C1(&myCONTROLLER0, vtarget, Vout_temp);

    EPWM_setCounterCompareValue(myEPWM0_BASE, EPWM_COUNTER_COMPARE_A, compBValue);
    //
    // Clear INT flag for this timer
    //
    EPWM_clearEventTriggerInterruptFlag(myEPWM0_BASE);
    //
    // Acknowledge interrupt group
    //
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP3);
}
```
这里最基本的处理比较简单。然后主循环中我只放了OLED的显示。要实现一个真正的数控电源还有很多需要完善。我这次还是本着体验下DSP与数控电源的结合参加的，哈哈。

# 四、效果展示与遇到的问题
## 效果展示
5V空载输出
![](./pic/现象1.png)
5V带载输出
![](./pic/现象2.png)
串口改变输出电压为6V
![](./pic/现象3.png)
6V空载
![](./pic/现象4.png)
增大输入电压
![](./pic/现象5.png)

## 遇到的问题
* 一开始碰到串口一直接收不到数据的情况，后来发现示例要打开FIFO接收，再从FIFO中读取
* I2C刚开始阻塞写入无效，发现也需要打开FIFO中断。
* EPWM一开始设置的一个事件触发一次中断，发现主循环一直卡住无法运行，发现是中断太频繁，占用时间过多，后来改成10个事件触发一次，才好些。
* PID控制器调参还是凭着感觉调的，调的很差，带载电流一大，电压就会下降。还在寻求解决办法。


# 五、未来的计划与感想

* 目前还只做了简单的buck环路，希望后面能完善成可自由升降压的。
* 过流保护和恒流输出还没做，也可以加入计划。
* 如果做成电压电流双环路控制，效果应该会好很多。
* 现在对DSP的认识还是一知半解，没单片机那么容易上手，水平基本还处于跑示例的程度。希望自己后面能够搞定。
