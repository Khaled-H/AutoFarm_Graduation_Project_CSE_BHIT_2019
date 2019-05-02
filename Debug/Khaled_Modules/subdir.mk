################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Khaled_Modules/ADC.c \
../Khaled_Modules/APP_CONFIGURATION_MODE.c \
../Khaled_Modules/DIO.c \
../Khaled_Modules/PORT.c 

OBJS += \
./Khaled_Modules/ADC.o \
./Khaled_Modules/APP_CONFIGURATION_MODE.o \
./Khaled_Modules/DIO.o \
./Khaled_Modules/PORT.o 

C_DEPS += \
./Khaled_Modules/ADC.d \
./Khaled_Modules/APP_CONFIGURATION_MODE.d \
./Khaled_Modules/DIO.d \
./Khaled_Modules/PORT.d 


# Each subdirectory must supply rules for building sources it contributes
Khaled_Modules/%.o: ../Khaled_Modules/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -I"E:\Faculty\A Faculty\4th-2 Fourth Year-2\Graduation_Project_Workspace\Application_Modules\Mostafa_Modules" -I"E:\Faculty\A Faculty\4th-2 Fourth Year-2\Graduation_Project_Workspace\Application_Modules\Manar_Modules" -I"E:\Faculty\A Faculty\4th-2 Fourth Year-2\Graduation_Project_Workspace\Application_Modules\Khaled_Modules" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


