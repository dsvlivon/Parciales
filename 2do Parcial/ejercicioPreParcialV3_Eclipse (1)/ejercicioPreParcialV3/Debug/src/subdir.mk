################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/Empleado.c \
../src/LinkedList.c \
../src/Menu.c \
../src/Parser.c \
../src/main.c \
../src/validations.c 

OBJS += \
./src/Controller.o \
./src/Empleado.o \
./src/LinkedList.o \
./src/Menu.o \
./src/Parser.o \
./src/main.o \
./src/validations.o 

C_DEPS += \
./src/Controller.d \
./src/Empleado.d \
./src/LinkedList.d \
./src/Menu.d \
./src/Parser.d \
./src/main.d \
./src/validations.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


