################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Manar_Modules/ACTUATORS.c \
../Manar_Modules/LCD.c \
../Manar_Modules/PROCESS.c \
../Manar_Modules/RCC.c \
../Manar_Modules/USART.c \
../Manar_Modules/WIFI.c \
../Manar_Modules/dh22.c 

OBJS += \
./Manar_Modules/ACTUATORS.o \
./Manar_Modules/LCD.o \
./Manar_Modules/PROCESS.o \
./Manar_Modules/RCC.o \
./Manar_Modules/USART.o \
./Manar_Modules/WIFI.o \
./Manar_Modules/dh22.o 

C_DEPS += \
./Manar_Modules/ACTUATORS.d \
./Manar_Modules/LCD.d \
./Manar_Modules/PROCESS.d \
./Manar_Modules/RCC.d \
./Manar_Modules/USART.d \
./Manar_Modules/WIFI.d \
./Manar_Modules/dh22.d 


# Each subdirectory must supply rules for building sources it contributes
Manar_Modules/%.o: ../Manar_Modules/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -I"E:\Faculty\A Faculty\4th-2 Fourth Year-2\Graduation_Project_Workspace\Application_Modules\Mostafa_Modules" -I"E:\Faculty\A Faculty\4th-2 Fourth Year-2\Graduation_Project_Workspace\Application_Modules\Manar_Modules" -I"E:\Faculty\A Faculty\4th-2 Fourth Year-2\Graduation_Project_Workspace\Application_Modules\Khaled_Modules" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


