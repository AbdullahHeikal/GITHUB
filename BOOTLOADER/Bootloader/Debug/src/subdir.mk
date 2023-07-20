################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HexParser_prg.c \
../src/MFMI_prg.c \
../src/MGPIO_prg.c \
../src/MRCC_prg.c \
../src/MSYSTICK_prg.c \
../src/UART2_prg.c \
../src/_write.c \
../src/main.c 

OBJS += \
./src/HexParser_prg.o \
./src/MFMI_prg.o \
./src/MGPIO_prg.o \
./src/MRCC_prg.o \
./src/MSYSTICK_prg.o \
./src/UART2_prg.o \
./src/_write.o \
./src/main.o 

C_DEPS += \
./src/HexParser_prg.d \
./src/MFMI_prg.d \
./src/MGPIO_prg.d \
./src/MRCC_prg.d \
./src/MSYSTICK_prg.d \
./src/UART2_prg.d \
./src/_write.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


