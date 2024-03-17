/*
 * drv_oled.c
 *
 *  Created on: 2024��3��16��
 *      Author: starry
 */


#include "drv_oled.h"
#include "oled_font.h"

#define Delay_MinTime               1*1000

//дһ���ֽ����ݵ�24C02
static int16_t EE24CX_Write_Byte(uint16_t ADDR,uint16_t Data)
{

    I2C_setDataCount(myI2C0_BASE,2);

    I2C_putData(myI2C0_BASE, ADDR);//ַ
    I2C_putData(myI2C0_BASE, Data);//

//    I2C_setConfig(myI2C0_BASE, I2C_MASTER_SEND_MODE);//
    I2C_sendStartCondition(myI2C0_BASE);//
    I2C_sendStopCondition(myI2C0_BASE);//
    DEVICE_DELAY_US(Delay_MinTime);
    return 0;
}


/**********************************************
// IIC Write Command
**********************************************/
void Write_IIC_Command(unsigned char IIC_Command)
{
//   IIC_Start();
//   Write_IIC_Byte(0x78);            //Slave address,SA0=0
//    IIC_Wait_Ack();
//   Write_IIC_Byte(0x00);            //write command
//    IIC_Wait_Ack();
//   Write_IIC_Byte(IIC_Command);
//    IIC_Wait_Ack();
//   IIC_Stop();

   I2C_setDataCount(myI2C0_BASE,2);

   I2C_putData(myI2C0_BASE, 0x00);//ַ
   I2C_putData(myI2C0_BASE, IIC_Command);//

    I2C_setConfig(myI2C0_BASE, I2C_MASTER_SEND_MODE);//
   I2C_sendStartCondition(myI2C0_BASE);//
   I2C_sendStopCondition(myI2C0_BASE);//
   DEVICE_DELAY_US(Delay_MinTime);

}
/**********************************************
// IIC Write Data
**********************************************/
void Write_IIC_Data(unsigned char IIC_Data)
{
//   IIC_Start();
//   Write_IIC_Byte(0x78);            //D/C#=0; R/W#=0
//    IIC_Wait_Ack();
//   Write_IIC_Byte(0x40);            //write data
//    IIC_Wait_Ack();
//   Write_IIC_Byte(IIC_Data);
//    IIC_Wait_Ack();
//   IIC_Stop();

   I2C_setDataCount(myI2C0_BASE,2);

   I2C_putData(myI2C0_BASE, 0x40);//ַ
   I2C_putData(myI2C0_BASE, IIC_Data);//

    I2C_setConfig(myI2C0_BASE, I2C_MASTER_SEND_MODE);//
   I2C_sendStartCondition(myI2C0_BASE);//
   I2C_sendStopCondition(myI2C0_BASE);//
   DEVICE_DELAY_US(Delay_MinTime);
}
void OLED_WR_Byte(unsigned char dat,unsigned char cmd)
{
    if(cmd)
            {

   Write_IIC_Data(dat);

        }
    else {
   Write_IIC_Command(dat);

    }

//    unsigned char temp_data=0;
//    if(cmd)
//        temp_data=0x40;
//
//    I2C_setDataCount(myI2C0_BASE,2);//
//    I2C_putData(myI2C0_BASE, temp_data);///ַ
//    I2C_putData(myI2C0_BASE, dat);//
//    I2C_setConfig(myI2C0_BASE, I2C_CONTROLLER_SEND_MODE);//
//    I2C_sendStartCondition(myI2C0_BASE);//
//    I2C_sendStopCondition(myI2C0_BASE);//
//    DEVICE_DELAY_US(Delay_MinTime);

}
void Delay_ms( uint32_t nCount)
{
    DEVICE_DELAY_US(nCount*1000);
}

/********************************************
// fill_Picture
********************************************/
void fill_picture(unsigned char fill_Data)
{
    unsigned char m,n;
    for(m=0;m<8;m++)
    {
        OLED_WR_Byte(0xb0+m,0);     //page0-page1
        OLED_WR_Byte(0x00,0);       //low column start address
        OLED_WR_Byte(0x10,0);       //high column start address
        for(n=0;n<128;n++)
            {
                OLED_WR_Byte(fill_Data,1);
            }
    }
}

//坐标设置

void OLED_Set_Pos(unsigned char x, unsigned char y)
{   OLED_WR_Byte(0xb0+y,OLED_CMD);
    OLED_WR_Byte(((x&0xf0)>>4)|0x10,OLED_CMD);
    OLED_WR_Byte((x&0x0f),OLED_CMD);
}
//开启OLED显示
void OLED_Display_On(void)
{
    OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC
    OLED_WR_Byte(0X14,OLED_CMD);  //DCDC ON
    OLED_WR_Byte(0XAF,OLED_CMD);  //DISPLAY ON
}
//关闭OLED显示
void OLED_Display_Off(void)
{
    OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC
    OLED_WR_Byte(0X10,OLED_CMD);  //DCDC OFF
    OLED_WR_Byte(0XAE,OLED_CMD);  //DISPLAY OFF
}
//清屏函数,清完屏,整个屏幕是黑色的!和没点亮一样!!!
void OLED_Clear(void)
{
    uint8_t i,n;
    for(i=0;i<8;i++)
    {
        OLED_WR_Byte (0xb0+i,OLED_CMD);    //设置页地址（0~7）
        OLED_WR_Byte (0x00,OLED_CMD);      //设置显示位置—列低地址ַ
        OLED_WR_Byte (0x10,OLED_CMD);      //设置显示位置—列高地址ַ
        for(n=0;n<128;n++)OLED_WR_Byte(0,OLED_DATA);
    }//更新显示
}
void OLED_On(void)
{
    uint8_t i,n;
    for(i=0;i<8;i++)
    {
        OLED_WR_Byte (0xb0+i,OLED_CMD);    //设置页地址（0~7）
        OLED_WR_Byte (0x00,OLED_CMD);      //设置显示位置—列低地址ַ
        OLED_WR_Byte (0x10,OLED_CMD);      //设置显示位置—列高地址ַ
        for(n=0;n<128;n++)OLED_WR_Byte(1,OLED_DATA);
    } //更新显示
}
//在指定位置显示一个字符,包括部分字符
//x:0~127
//y:0~63
//mode:0,反白显示;1,正常显示
//size:选择字体 16/12
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t Char_Size)
{
    unsigned char c=0,i=0;
        c=chr-' ';//得到偏移后的值         ֵ
        if(x>Max_Column-1){x=0;y=y+2;}
        if(Char_Size ==16)
            {
            OLED_Set_Pos(x,y);
            for(i=0;i<8;i++)
            OLED_WR_Byte(F8X16[c*16+i],OLED_DATA);
            OLED_Set_Pos(x,y+1);
            for(i=0;i<8;i++)
            OLED_WR_Byte(F8X16[c*16+i+8],OLED_DATA);
            }
            else {
                OLED_Set_Pos(x,y);
                for(i=0;i<6;i++)
                OLED_WR_Byte(F6x8[c][i],OLED_DATA);

            }
}
//m^n函数
uint32_t oled_pow(uint8_t m,uint8_t n)
{
    uint32_t result=1;
    while(n--)result*=m;
    return result;
}
//显示2个数字
//x,y :起点坐标
//len :数字的位数
//size:字体大小
//mode:模式   0,填充模式;1,叠加模式
//num:数值(0~4294967295);
void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size2)
{
    uint8_t t,temp;
    uint8_t enshow=0;
    for(t=0;t<len;t++)
    {
        temp=(num/oled_pow(10,len-t-1))%10;
        if(enshow==0&&t<(len-1))
        {
            if(temp==0)
            {
                OLED_ShowChar(x+(size2/2)*t,y,' ',size2);
                continue;
            }else enshow=1;

        }
        OLED_ShowChar(x+(size2/2)*t,y,temp+'0',size2);
    }
}
//显示一个字符号串
void OLED_ShowString(uint8_t x,uint8_t y,uint8_t *chr,uint8_t Char_Size)
{
    unsigned char j=0;
    while (chr[j]!='\0')
    {       OLED_ShowChar(x,y,chr[j],Char_Size);
            x+=8;
        if(x>120){x=0;y+=2;}
            j++;
    }
}
//显示汉字
void OLED_ShowCHinese(uint8_t x,uint8_t y,uint8_t no)
{
//    uint8_t t,adder=0;
//    OLED_Set_Pos(x,y);
//    for(t=0;t<16;t++)
//        {
//                OLED_WR_Byte(Hzk[2*no][t],OLED_DATA);
//                adder+=1;
//     }
//        OLED_Set_Pos(x,y+1);
//    for(t=0;t<16;t++)
//            {
//                OLED_WR_Byte(Hzk[2*no+1][t],OLED_DATA);
//                adder+=1;
//      }
}
/***********功能描述：显示显示BMP图片128×64起始点坐标(x,y),x的范围0～127，y为页的范围0～7*****************/
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[])
{
 unsigned int j=0;
 unsigned char x,y;

  if(y1%8==0) y=y1/8;
  else y=y1/8+1;
    for(y=y0;y<y1;y++)
    {
        OLED_Set_Pos(x0,y);
    for(x=x0;x<x1;x++)
        {
            OLED_WR_Byte(BMP[j++],OLED_DATA);
        }
    }
}


void Oled_Init()
{
    Delay_ms(100); //�ȴ�ϵͳ�ȶ�

      OLED_WR_Byte(0xAE,OLED_CMD);//--display off
        OLED_WR_Byte(0x00,OLED_CMD);//---set low column address
        OLED_WR_Byte(0x10,OLED_CMD);//---set high column address
        OLED_WR_Byte(0x40,OLED_CMD);//--set start line address
        OLED_WR_Byte(0xB0,OLED_CMD);//--set page address
        OLED_WR_Byte(0x81,OLED_CMD); // contract control
        OLED_WR_Byte(0xFF,OLED_CMD);//--128
        OLED_WR_Byte(0xA1,OLED_CMD);//set segment remap
        OLED_WR_Byte(0xA6,OLED_CMD);//--normal / reverse
        OLED_WR_Byte(0xA8,OLED_CMD);//--set multiplex ratio(1 to 64)
        OLED_WR_Byte(0x3F,OLED_CMD);//--1/32 duty
        OLED_WR_Byte(0xC8,OLED_CMD);//Com scan direction
        OLED_WR_Byte(0xD3,OLED_CMD);//-set display offset
        OLED_WR_Byte(0x00,OLED_CMD);//

        OLED_WR_Byte(0xD5,OLED_CMD);//set osc division
        OLED_WR_Byte(0x80,OLED_CMD);//

        OLED_WR_Byte(0xD8,OLED_CMD);//set area color mode off
        OLED_WR_Byte(0x05,OLED_CMD);//

        OLED_WR_Byte(0xD9,OLED_CMD);//Set Pre-Charge Period
        OLED_WR_Byte(0xF1,OLED_CMD);//

        OLED_WR_Byte(0xDA,OLED_CMD);//set com pin configuartion
        OLED_WR_Byte(0x12,OLED_CMD);//

        OLED_WR_Byte(0xDB,OLED_CMD);//set Vcomh
        OLED_WR_Byte(0x30,OLED_CMD);//

        OLED_WR_Byte(0x8D,OLED_CMD);//set charge pump enable
        OLED_WR_Byte(0x14,OLED_CMD);//

        OLED_WR_Byte(0xAF,OLED_CMD);//--turn on oled panel
        Delay_ms(10);     //等待数据稳定
        OLED_Clear();     //再次清屏
        Delay_ms(10);     //等待数据稳定
}

void OLED_DISPLAY_INT(void)
{
    OLED_Clear();     //清屏
    Delay_ms(1);     //等待数据稳定
    OLED_Clear();     //再次清屏
    Delay_ms(1);     //等待数据稳定

  OLED_ShowString(2,0,"Vin:",16);
  OLED_ShowChar(66,0,'.',16);
  OLED_ShowString(90,0,"V",16);
  OLED_ShowString(2,2,"Vout:",16);
  OLED_ShowChar(66,2,'.',16);
  OLED_ShowString(90,2,"V",16);

  OLED_ShowString(2,4,"Power_State:",16);
  OLED_ShowString(2,6,"ok",16);
}

void DISPLAY_Voltage(float V1,float V2)
{
    char float_buffer[20]={0};
    sprintf(float_buffer,"%2.1f",V1);
    OLED_ShowString(50,0,float_buffer,16);
    sprintf(float_buffer,"%2.1f",V2);
    OLED_ShowString(50,2,float_buffer,16);
}

void DISPLAY_Voltage_TT(unsigned char  V1H,unsigned char  V1L,unsigned char  V2H,unsigned char  V2L)
{
//    char float_buffer[20]={0};
//    sprintf(float_buffer,"%2.1f",V1);
//    OLED_ShowString(50,0,float_buffer,16);
//    sprintf(float_buffer,"%2.1f",V2);
//    OLED_ShowString(50,2,float_buffer,16);
}



