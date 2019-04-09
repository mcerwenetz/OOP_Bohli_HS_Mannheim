################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../IntVector.cpp \
../int_vector_main.cpp \
../ooptool.cpp 

OBJS += \
./IntVector.o \
./int_vector_main.o \
./ooptool.o 

CPP_DEPS += \
./IntVector.d \
./int_vector_main.d \
./ooptool.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


