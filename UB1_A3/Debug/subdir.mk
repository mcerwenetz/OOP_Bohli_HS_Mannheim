################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../gtest_main.cpp \
../tausche.cpp \
../test_tausche.cpp 

OBJS += \
./gtest_main.o \
./tausche.o \
./test_tausche.o 

CPP_DEPS += \
./gtest_main.d \
./tausche.d \
./test_tausche.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


