################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include mbed-os/rtos/rtx/TARGET_CORTEX_M/TARGET_RTOS_M4_M7/TOOLCHAIN_GCC/subdir.mk
-include mbed-os/rtos/rtx/TARGET_CORTEX_M/subdir.mk
-include mbed-os/rtos/rtos/subdir.mk
-include mbed-os/hal/targets/hal/TARGET_Freescale/TARGET_KSDK2_MCUS/api/subdir.mk
-include mbed-os/hal/targets/hal/TARGET_Freescale/TARGET_KSDK2_MCUS/TARGET_MCU_K64F/drivers/subdir.mk
-include mbed-os/hal/targets/hal/TARGET_Freescale/TARGET_KSDK2_MCUS/TARGET_MCU_K64F/TARGET_HEXIWEAR/subdir.mk
-include mbed-os/hal/targets/hal/TARGET_Freescale/TARGET_KSDK2_MCUS/TARGET_MCU_K64F/subdir.mk
-include mbed-os/hal/targets/cmsis/TARGET_Freescale/TARGET_MCU_K64F/TOOLCHAIN_GCC_ARM/subdir.mk
-include mbed-os/hal/targets/cmsis/TARGET_Freescale/TARGET_MCU_K64F/subdir.mk
-include mbed-os/hal/common/subdir.mk
-include mbed-os/features/net/network-socket/subdir.mk
-include mbed-os/features/mbedtls/src/subdir.mk
-include mbed-os/features/frameworks/utest/source/subdir.mk
-include mbed-os/features/frameworks/utest/subdir.mk
-include mbed-os/features/frameworks/unity/source/subdir.mk
-include mbed-os/features/frameworks/greentea-client/source/subdir.mk
-include images/subdir.mk
-include Hexi_OLED_SSD1351/OpenSans_Font/subdir.mk
-include Hexi_OLED_SSD1351/subdir.mk
-include Hexi_KW40Z/subdir.mk
-include FXOS8700CQ/subdir.mk
-include .metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
hackster_contest_gym_watch.bin \

SECONDARY_SIZE += \
hackster_contest_gym_watch.siz \


# All Target
all: hackster_contest_gym_watch.elf secondary-outputs

# Tool invocations
hackster_contest_gym_watch.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM C++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-builtin -Wall  -g -ggdb -T "C:\Users\vntfene\Documents\hexiwear\hackster_contest_gym_watch\mbed-os\hal\targets\cmsis\TARGET_Freescale\TARGET_MCU_K64F\TOOLCHAIN_GCC_ARM\MK64FN1M0xxx12.ld" -Xlinker --gc-sections -Wl,-Map,"hackster_contest_gym_watch.map" -specs=nosys.specs -o "hackster_contest_gym_watch.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

hackster_contest_gym_watch.bin: hackster_contest_gym_watch.elf
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	arm-none-eabi-objcopy -O binary "hackster_contest_gym_watch.elf"  "hackster_contest_gym_watch.bin"
	@echo 'Finished building: $@'
	@echo ' '

hackster_contest_gym_watch.siz: hackster_contest_gym_watch.elf
	@echo 'Invoking: Cross ARM GNU Print Size'
	arm-none-eabi-size --format=berkeley "hackster_contest_gym_watch.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(C++_DEPS)$(OBJS)$(C_DEPS)$(ASM_DEPS)$(CC_DEPS)$(SECONDARY_FLASH)$(CPP_DEPS)$(CXX_DEPS)$(C_UPPER_DEPS)$(S_UPPER_DEPS) hackster_contest_gym_watch.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
