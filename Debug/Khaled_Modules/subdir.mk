################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Khaled_Modules/DIO.c \
../Khaled_Modules/DIO_TEST_UNIT.c \
../Khaled_Modules/PORT.c \
../Khaled_Modules/PORT_TEST_UNIT.c \
../Khaled_Modules/test.c 

OBJS += \
./Khaled_Modules/DIO.o \
./Khaled_Modules/DIO_TEST_UNIT.o \
./Khaled_Modules/PORT.o \
./Khaled_Modules/PORT_TEST_UNIT.o \
./Khaled_Modules/test.o 

C_DEPS += \
./Khaled_Modules/DIO.d \
./Khaled_Modules/DIO_TEST_UNIT.d \
./Khaled_Modules/PORT.d \
./Khaled_Modules/PORT_TEST_UNIT.d \
./Khaled_Modules/test.d 


# Each subdirectory must supply rules for building sources it contributes
Khaled_Modules/%.o: ../Khaled_Modules/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


