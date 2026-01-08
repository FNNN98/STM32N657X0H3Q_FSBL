################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32n657x0hxq_fsbl.s 

OBJS += \
./Startup/startup_stm32n657x0hxq_fsbl.o 

S_DEPS += \
./Startup/startup_stm32n657x0hxq_fsbl.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/%.o: ../Startup/%.s Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m55 -g3 -DDEBUG -c -I"C:/Users/fredd/STM32CubeIDE/workspace_1.15.0/STM32N657X0H3Q/FSBL/Inc" -I"C:/Users/fredd/STM32CubeIDE/workspace_1.15.0/STM32N657X0H3Q/FSBL/Src" -I"C:/Users/fredd/STM32CubeIDE/workspace_1.15.0/STM32N657X0H3Q/FSBL/Startup" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Startup

clean-Startup:
	-$(RM) ./Startup/startup_stm32n657x0hxq_fsbl.d ./Startup/startup_stm32n657x0hxq_fsbl.o

.PHONY: clean-Startup

