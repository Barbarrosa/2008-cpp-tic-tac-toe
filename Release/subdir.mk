################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../AI.cpp \
../Board.cpp \
../O.cpp \
../Shared.cpp \
../TicMain.cpp \
../TicMenu.cpp \
../TicTypeMenu.cpp \
../X.cpp 

CPP_DEPS += \
./AI.d \
./Board.d \
./O.d \
./Shared.d \
./TicMain.d \
./TicMenu.d \
./TicTypeMenu.d \
./X.d 

OBJS += \
./AI.o \
./Board.o \
./O.o \
./Shared.o \
./TicMain.o \
./TicMenu.o \
./TicTypeMenu.o \
./X.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


