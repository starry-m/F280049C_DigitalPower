################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/workTools/ti/ccs1260/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS

GEN_OPTS__FLAG := --cmd_file="syscfg/board.opt" --cmd_file="syscfg/device_cmd.opt" --cmd_file="syscfg/c2000ware_libraries.opt" 
GEN_CMDS__FLAG := -l"syscfg/device_cmd.cmd" 

ORDERED_OBJS += \
"./syscfg/board.obj" \
"./syscfg/device.obj" \
"./syscfg/device_cmd.obj" \
"./syscfg/c2000ware_libraries.obj" \
"./f28004x_codestartbranch.obj" \
"./DCL_clamp_C1.obj" \
"./DCL_DF11_C1.obj" \
"./DCL_DF13_C1.obj" \
"./DCL_DF13_C2C3.obj" \
"./DCL_DF22_C1.obj" \
"./DCL_DF22_C2C3.obj" \
"./DCL_DF23_C1.obj" \
"./DCL_DF23_C2C3.obj" \
"./DCL_error.obj" \
"./DCL_futils.obj" \
"./DCL_PI_C1.obj" \
"./DCL_PI_C4.obj" \
"./DCL_PI_C7.obj" \
"./DCL_PID_C1.obj" \
"./DCL_PID_C4.obj" \
"./common.obj" \
"./drv_oled.obj" \
"./main.obj" \
"./state_machine.obj" \
"../280049C_FLASH_lnk.cmd" \
$(GEN_CMDS__FLAG) \
-lc2000ware_libraries.cmd.genlibs \
-lboard.cmd.genlibs \
-ldevice_cmd.cmd.genlibs \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
F280049C_Demo.out 

EXE_OUTPUTS__QUOTED += \
"F280049C_Demo.out" 


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "F280049C_Demo.out"

# Tool invocations
F280049C_Demo.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"D:/workTools/ti/ccs1260/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -Ooff --define=DEBUG --define=_FLASH --define=generic_flash_lnk --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi -z -m"F280049C_Demo.map" --heap_size=0x200 --stack_size=0x3F8 --warn_sections -i"D:/workTools/ti/ccs1260/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/lib" -i"D:/workTools/ti/c2000/C2000Ware_5_01_00_00" -i"D:/1my_program_study/2024_winter_task/280049C/workSpace/F280049C_Demo/CPU1_FLASH/syscfg" -i"D:/workTools/ti/ccs1260/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --reread_libs --define=_FLASH --define=generic_flash_lnk --diag_wrap=off --display_error_number --xml_link_info="F280049C_Demo_linkInfo.xml" --entry_point=code_start --rom_model -o "F280049C_Demo.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "syscfg\board.obj" "syscfg\device.obj" "syscfg\device_cmd.obj" "syscfg\c2000ware_libraries.obj" "f28004x_codestartbranch.obj" "DCL_clamp_C1.obj" "DCL_DF11_C1.obj" "DCL_DF13_C1.obj" "DCL_DF13_C2C3.obj" "DCL_DF22_C1.obj" "DCL_DF22_C2C3.obj" "DCL_DF23_C1.obj" "DCL_DF23_C2C3.obj" "DCL_error.obj" "DCL_futils.obj" "DCL_PI_C1.obj" "DCL_PI_C4.obj" "DCL_PI_C7.obj" "DCL_PID_C1.obj" "DCL_PID_C4.obj" "common.obj" "drv_oled.obj" "main.obj" "state_machine.obj" 
	-$(RM) "syscfg\board.d" "syscfg\device.d" "syscfg\device_cmd.d" "syscfg\c2000ware_libraries.d" "DCL_error.d" "common.d" "drv_oled.d" "main.d" "state_machine.d" 
	-$(RM) "f28004x_codestartbranch.d" "DCL_clamp_C1.d" "DCL_DF11_C1.d" "DCL_DF13_C1.d" "DCL_DF13_C2C3.d" "DCL_DF22_C1.d" "DCL_DF22_C2C3.d" "DCL_DF23_C1.d" "DCL_DF23_C2C3.d" "DCL_futils.d" "DCL_PI_C1.d" "DCL_PI_C4.d" "DCL_PI_C7.d" "DCL_PID_C1.d" "DCL_PID_C4.d" 
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-echo "========= Build of the CLB simulation has moved to the CLB Tool. Click the '?' icon by the _Generate CLB Simulation File_ enable for more details (located in the Global Parameters of the Tile Design SysConfig module) ============="
	-if 0 == 1  D:/workTools/ti/ccs1260/ccs/tools/node/node.exe "D:/workTools/ti/c2000/C2000Ware_5_01_00_00/utilities/clb_tool/clb_syscfg/dot_file_libraries/clbDotUtility.js"  "D:/workTools/ti/c2000/C2000Ware_5_01_00_00/utilities/clb_tool/clb_syscfg/" "D:/1my_program_study/2024_winter_task/280049C/workSpace/F280049C_Demo/CPU1_FLASH/syscfg" "D:/1my_program_study/2024_winter_task/280049C/workSpace/F280049C_Demo/CPU1_FLASH/syscfg/clb.dot"
	-if 0 == 1  mkdir "D:/1my_program_study/2024_winter_task/280049C/workSpace/F280049C_Demo/CPU1_FLASH/diagrams"
	-if 0 == 1  D:/workTools/ti/ccs1260/ccs/tools/node/node.exe "D:/workTools/ti/c2000/C2000Ware_5_01_00_00/driverlib/.meta/generate_diagrams.js" "D:/workTools/ti/c2000/C2000Ware_5_01_00_00" "D:/1my_program_study/2024_winter_task/280049C/workSpace/F280049C_Demo/CPU1_FLASH/diagrams" "D:/1my_program_study/2024_winter_task/280049C/workSpace/F280049C_Demo/CPU1_FLASH/syscfg"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

