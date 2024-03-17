################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../280049C_FLASH_lnk.cmd 

SYSCFG_SRCS += \
../F280049C_Demo.syscfg 

ASM_SRCS += \
D:/workTools/ti/c2000/C2000Ware_5_01_00_00/device_support/f28004x/common/source/f28004x_codestartbranch.asm \
D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_clamp_C1.asm \
D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_DF11_C1.asm \
D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_DF13_C1.asm \
D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_DF13_C2C3.asm \
D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_DF22_C1.asm \
D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_DF22_C2C3.asm \
D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_DF23_C1.asm \
D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_DF23_C2C3.asm \
D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_futils.asm \
D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_PI_C1.asm \
D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_PI_C4.asm \
D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_PI_C7.asm \
D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_PID_C1.asm \
D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_PID_C4.asm 

C_SRCS += \
./syscfg/board.c \
./syscfg/device.c \
./syscfg/device_cmd.c \
./syscfg/c2000ware_libraries.c \
D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_error.c \
../common.c \
../drv_oled.c \
../main.c \
../state_machine.c 

GEN_CMDS += \
./syscfg/device_cmd.cmd 

GEN_FILES += \
./syscfg/board.c \
./syscfg/board.opt \
./syscfg/device.c \
./syscfg/device_cmd.cmd \
./syscfg/device_cmd.c \
./syscfg/device_cmd.opt \
./syscfg/c2000ware_libraries.opt \
./syscfg/c2000ware_libraries.c 

GEN_MISC_DIRS += \
./syscfg 

C_DEPS += \
./syscfg/board.d \
./syscfg/device.d \
./syscfg/device_cmd.d \
./syscfg/c2000ware_libraries.d \
./DCL_error.d \
./common.d \
./drv_oled.d \
./main.d \
./state_machine.d 

GEN_OPTS += \
./syscfg/board.opt \
./syscfg/device_cmd.opt \
./syscfg/c2000ware_libraries.opt 

OBJS += \
./syscfg/board.obj \
./syscfg/device.obj \
./syscfg/device_cmd.obj \
./syscfg/c2000ware_libraries.obj \
./f28004x_codestartbranch.obj \
./DCL_clamp_C1.obj \
./DCL_DF11_C1.obj \
./DCL_DF13_C1.obj \
./DCL_DF13_C2C3.obj \
./DCL_DF22_C1.obj \
./DCL_DF22_C2C3.obj \
./DCL_DF23_C1.obj \
./DCL_DF23_C2C3.obj \
./DCL_error.obj \
./DCL_futils.obj \
./DCL_PI_C1.obj \
./DCL_PI_C4.obj \
./DCL_PI_C7.obj \
./DCL_PID_C1.obj \
./DCL_PID_C4.obj \
./common.obj \
./drv_oled.obj \
./main.obj \
./state_machine.obj 

ASM_DEPS += \
./f28004x_codestartbranch.d \
./DCL_clamp_C1.d \
./DCL_DF11_C1.d \
./DCL_DF13_C1.d \
./DCL_DF13_C2C3.d \
./DCL_DF22_C1.d \
./DCL_DF22_C2C3.d \
./DCL_DF23_C1.d \
./DCL_DF23_C2C3.d \
./DCL_futils.d \
./DCL_PI_C1.d \
./DCL_PI_C4.d \
./DCL_PI_C7.d \
./DCL_PID_C1.d \
./DCL_PID_C4.d 

GEN_MISC_FILES += \
./syscfg/board.h \
./syscfg/board.cmd.genlibs \
./syscfg/pinmux.csv \
./syscfg/epwm.dot \
./syscfg/device.h \
./syscfg/adc.dot \
./syscfg/device_cmd.h \
./syscfg/device_cmd.cmd.genlibs \
./syscfg/c2000ware_libraries.cmd.genlibs \
./syscfg/c2000ware_libraries.h \
./syscfg/clocktree.h 

GEN_MISC_DIRS__QUOTED += \
"syscfg" 

OBJS__QUOTED += \
"syscfg\board.obj" \
"syscfg\device.obj" \
"syscfg\device_cmd.obj" \
"syscfg\c2000ware_libraries.obj" \
"f28004x_codestartbranch.obj" \
"DCL_clamp_C1.obj" \
"DCL_DF11_C1.obj" \
"DCL_DF13_C1.obj" \
"DCL_DF13_C2C3.obj" \
"DCL_DF22_C1.obj" \
"DCL_DF22_C2C3.obj" \
"DCL_DF23_C1.obj" \
"DCL_DF23_C2C3.obj" \
"DCL_error.obj" \
"DCL_futils.obj" \
"DCL_PI_C1.obj" \
"DCL_PI_C4.obj" \
"DCL_PI_C7.obj" \
"DCL_PID_C1.obj" \
"DCL_PID_C4.obj" \
"common.obj" \
"drv_oled.obj" \
"main.obj" \
"state_machine.obj" 

GEN_MISC_FILES__QUOTED += \
"syscfg\board.h" \
"syscfg\board.cmd.genlibs" \
"syscfg\pinmux.csv" \
"syscfg\epwm.dot" \
"syscfg\device.h" \
"syscfg\adc.dot" \
"syscfg\device_cmd.h" \
"syscfg\device_cmd.cmd.genlibs" \
"syscfg\c2000ware_libraries.cmd.genlibs" \
"syscfg\c2000ware_libraries.h" \
"syscfg\clocktree.h" 

C_DEPS__QUOTED += \
"syscfg\board.d" \
"syscfg\device.d" \
"syscfg\device_cmd.d" \
"syscfg\c2000ware_libraries.d" \
"DCL_error.d" \
"common.d" \
"drv_oled.d" \
"main.d" \
"state_machine.d" 

GEN_FILES__QUOTED += \
"syscfg\board.c" \
"syscfg\board.opt" \
"syscfg\device.c" \
"syscfg\device_cmd.cmd" \
"syscfg\device_cmd.c" \
"syscfg\device_cmd.opt" \
"syscfg\c2000ware_libraries.opt" \
"syscfg\c2000ware_libraries.c" 

ASM_DEPS__QUOTED += \
"f28004x_codestartbranch.d" \
"DCL_clamp_C1.d" \
"DCL_DF11_C1.d" \
"DCL_DF13_C1.d" \
"DCL_DF13_C2C3.d" \
"DCL_DF22_C1.d" \
"DCL_DF22_C2C3.d" \
"DCL_DF23_C1.d" \
"DCL_DF23_C2C3.d" \
"DCL_futils.d" \
"DCL_PI_C1.d" \
"DCL_PI_C4.d" \
"DCL_PI_C7.d" \
"DCL_PID_C1.d" \
"DCL_PID_C4.d" 

SYSCFG_SRCS__QUOTED += \
"../F280049C_Demo.syscfg" 

C_SRCS__QUOTED += \
"./syscfg/board.c" \
"./syscfg/device.c" \
"./syscfg/device_cmd.c" \
"./syscfg/c2000ware_libraries.c" \
"D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_error.c" \
"../common.c" \
"../drv_oled.c" \
"../main.c" \
"../state_machine.c" 

ASM_SRCS__QUOTED += \
"D:/workTools/ti/c2000/C2000Ware_5_01_00_00/device_support/f28004x/common/source/f28004x_codestartbranch.asm" \
"D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_clamp_C1.asm" \
"D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_DF11_C1.asm" \
"D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_DF13_C1.asm" \
"D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_DF13_C2C3.asm" \
"D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_DF22_C1.asm" \
"D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_DF22_C2C3.asm" \
"D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_DF23_C1.asm" \
"D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_DF23_C2C3.asm" \
"D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_futils.asm" \
"D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_PI_C1.asm" \
"D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_PI_C4.asm" \
"D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_PI_C7.asm" \
"D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_PID_C1.asm" \
"D:/workTools/ti/c2000/C2000Ware_5_01_00_00/libraries/control/DCL/c28/source/DCL_PID_C4.asm" 


