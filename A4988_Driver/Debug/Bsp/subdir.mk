################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Bsp/StepperMotor_A4988.c 

OBJS += \
./Bsp/StepperMotor_A4988.o 

C_DEPS += \
./Bsp/StepperMotor_A4988.d 


# Each subdirectory must supply rules for building sources it contributes
Bsp/%.o Bsp/%.su Bsp/%.cyclo: ../Bsp/%.c Bsp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -c -I"C:/Users/Phuri/STM32CubeIDE/A4988_Stepper/A4988_Driver/Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Bsp

clean-Bsp:
	-$(RM) ./Bsp/StepperMotor_A4988.cyclo ./Bsp/StepperMotor_A4988.d ./Bsp/StepperMotor_A4988.o ./Bsp/StepperMotor_A4988.su

.PHONY: clean-Bsp

