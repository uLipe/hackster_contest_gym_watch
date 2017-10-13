################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mbed-os/rtos/rtx/TARGET_CORTEX_M/HAL_CM.c \
../mbed-os/rtos/rtx/TARGET_CORTEX_M/RTX_Conf_CM.c \
../mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_CMSIS.c \
../mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Event.c \
../mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_List.c \
../mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Mailbox.c \
../mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_MemBox.c \
../mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Memory.c \
../mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Mutex.c \
../mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_OsEventObserver.c \
../mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Robin.c \
../mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Semaphore.c \
../mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_System.c \
../mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Task.c \
../mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Time.c \
../mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Timer.c 

OBJS += \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/HAL_CM.o \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/RTX_Conf_CM.o \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_CMSIS.o \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Event.o \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_List.o \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Mailbox.o \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_MemBox.o \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Memory.o \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Mutex.o \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_OsEventObserver.o \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Robin.o \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Semaphore.o \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_System.o \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Task.o \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Time.o \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Timer.o 

C_DEPS += \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/HAL_CM.d \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/RTX_Conf_CM.d \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_CMSIS.d \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Event.d \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_List.d \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Mailbox.d \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_MemBox.d \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Memory.d \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Mutex.d \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_OsEventObserver.d \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Robin.d \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Semaphore.d \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_System.d \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Task.d \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Time.d \
./mbed-os/rtos/rtx/TARGET_CORTEX_M/rt_Timer.d 


# Each subdirectory must supply rules for building sources it contributes
mbed-os/rtos/rtx/TARGET_CORTEX_M/%.o: ../mbed-os/rtos/rtx/TARGET_CORTEX_M/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-builtin -Wall  -g -ggdb -DMBED_BUILD_TIMESTAMP=1475702714.0 -D__MBED__=1 -DDEVICE_I2CSLAVE=1 -DTARGET_LIKE_MBED -DTARGET_Freescale -DDEVICE_PORTINOUT=1 -DTARGET_RTOS_M4_M7 -DDEVICE_RTC=1 -DTOOLCHAIN_object -D__CMSIS_RTOS -DFSL_RTOS_MBED -DTARGET_HEXIWEAR -DTARGET_CORTEX_M -DTARGET_KSDK2_MCUS -DTARGET_LIKE_CORTEX_M4 -DDEVICE_ANALOGOUT=1 -DTARGET_M4 -DTARGET_UVISOR_UNSUPPORTED -DTARGET_K64F -DDEVICE_SERIAL=1 -DDEVICE_INTERRUPTIN=1 -DDEVICE_I2C=1 -DDEVICE_PORTOUT=1 -D__CORTEX_M4 -DDEVICE_STDIO_MESSAGES=1 -DCPU_MK64FN1M0VMD12 -D__FPU_PRESENT=1 -DDEVICE_PORTIN=1 -DTARGET_RELEASE -DDEVICE_SERIAL_FC=1 -DTOOLCHAIN_GCC -D__MBED_CMSIS_RTOS_CM -DDEVICE_SLEEP=1 -DTOOLCHAIN_GCC_ARM -DDEVICE_SPI=1 -DDEVICE_ERROR_RED=1 -DDEVICE_SPISLAVE=1 -DDEVICE_ANALOGIN=1 -DDEVICE_PWMOUT=1 -DTARGET_MCU_K64F -DARM_MATH_CM4 -I"/Users/user/Documents/devel/hackster_contest_gym_watch" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/FXOS8700CQ" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/Hexi_OLED_SSD1351" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/Hexi_OLED_SSD1351/OpenSans_Font" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/Hexi_KW40Z" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/features" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/features/frameworks" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/features/frameworks/greentea-client" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/features/frameworks/greentea-client/greentea-client" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/features/frameworks/greentea-client/source" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/features/frameworks/unity" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/features/frameworks/unity/source" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/features/frameworks/unity/unity" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/features/frameworks/utest" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/features/frameworks/utest/source" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/features/frameworks/utest/utest" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/features/mbedtls" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/features/mbedtls/inc" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/features/mbedtls/inc/mbedtls" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/features/mbedtls/src" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/features/net" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/features/net/network-socket" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/hal" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/hal/api" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/hal/common" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/hal/hal" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/hal/hal/storage_abstraction" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/hal/targets" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/hal/targets/cmsis" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/hal/targets/cmsis/TARGET_Freescale" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/hal/targets/cmsis/TARGET_Freescale/TARGET_MCU_K64F" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/hal/targets/cmsis/TARGET_Freescale/TARGET_MCU_K64F/TOOLCHAIN_GCC_ARM" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/hal/targets/hal" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/hal/targets/hal/TARGET_Freescale" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/hal/targets/hal/TARGET_Freescale/TARGET_KSDK2_MCUS" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/hal/targets/hal/TARGET_Freescale/TARGET_KSDK2_MCUS/TARGET_MCU_K64F" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/hal/targets/hal/TARGET_Freescale/TARGET_KSDK2_MCUS/TARGET_MCU_K64F/TARGET_HEXIWEAR" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/hal/targets/hal/TARGET_Freescale/TARGET_KSDK2_MCUS/TARGET_MCU_K64F/drivers" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/hal/targets/hal/TARGET_Freescale/TARGET_KSDK2_MCUS/api" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/rtos" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/rtos/rtos" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/rtos/rtx" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/rtos/rtx/TARGET_CORTEX_M" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/rtos/rtx/TARGET_CORTEX_M/TARGET_RTOS_M4_M7" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/mbed-os/rtos/rtx/TARGET_CORTEX_M/TARGET_RTOS_M4_M7/TOOLCHAIN_GCC" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/ugfx_2.7" -I"/Users/user/Documents/devel/hackster_contest_gym_watch/ugfx_2.7/drivers/gdisp/SSD1351" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


