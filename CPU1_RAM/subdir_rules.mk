################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-1318847713: ../F280049C_Demo.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"D:/workTools/ti/sysconfig_1.19.0/sysconfig_cli.bat" --script "D:/1my_program_study/2024_winter_task/280049C/workSpace/F280049C_Demo/F280049C_Demo.syscfg" -o "syscfg" -s "D:/workTools/ti/c2000/C2000Ware_5_01_00_00/.metadata/sdk.json" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-1318847713 ../F280049C_Demo.syscfg
syscfg/board.h: build-1318847713
syscfg/board.cmd.genlibs: build-1318847713
syscfg/board.opt: build-1318847713
syscfg/pinmux.csv: build-1318847713
syscfg/epwm.dot: build-1318847713
syscfg/device.c: build-1318847713
syscfg/device.h: build-1318847713
syscfg/adc.dot: build-1318847713
syscfg/device_cmd.cmd: build-1318847713
syscfg/device_cmd.c: build-1318847713
syscfg/device_cmd.h: build-1318847713
syscfg/device_cmd.opt: build-1318847713
syscfg/device_cmd.cmd.genlibs: build-1318847713
syscfg/c2000ware_libraries.cmd.genlibs: build-1318847713
syscfg/c2000ware_libraries.opt: build-1318847713
syscfg/c2000ware_libraries.c: build-1318847713
syscfg/c2000ware_libraries.h: build-1318847713
syscfg/clocktree.h: build-1318847713
syscfg: build-1318847713

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/workTools/ti/ccs1260/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -Ooff --include_path="D:/1my_program_study/2024_winter_task/280049C/workSpace/F280049C_Demo" --include_path="D:/workTools/ti/c2000/C2000Ware_5_01_00_00" --include_path="D:/workTools/ti/ccs1260/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --define=generic_ram_lnk --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="D:/1my_program_study/2024_winter_task/280049C/workSpace/F280049C_Demo/CPU1_RAM/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f28004x_codestartbranch.obj: D:/workTools/ti/c2000/C2000Ware_5_01_00_00/device_support/f28004x/common/source/f28004x_codestartbranch.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/workTools/ti/ccs1260/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -Ooff --include_path="D:/1my_program_study/2024_winter_task/280049C/workSpace/F280049C_Demo" --include_path="D:/workTools/ti/c2000/C2000Ware_5_01_00_00" --include_path="D:/workTools/ti/ccs1260/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --define=generic_ram_lnk --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="D:/1my_program_study/2024_winter_task/280049C/workSpace/F280049C_Demo/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/workTools/ti/ccs1260/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -Ooff --include_path="D:/1my_program_study/2024_winter_task/280049C/workSpace/F280049C_Demo" --include_path="D:/workTools/ti/c2000/C2000Ware_5_01_00_00" --include_path="D:/workTools/ti/ccs1260/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --define=generic_ram_lnk --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="D:/1my_program_study/2024_winter_task/280049C/workSpace/F280049C_Demo/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


