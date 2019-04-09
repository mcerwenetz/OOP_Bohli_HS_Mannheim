################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ooptool.cpp \
../participants.cpp \
../race_main.cpp \
../time.cpp 

OBJS += \
./ooptool.o \
./participants.o \
./race_main.o \
./time.o 

CPP_DEPS += \
./ooptool.d \
./participants.d \
./race_main.d \
./time.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


