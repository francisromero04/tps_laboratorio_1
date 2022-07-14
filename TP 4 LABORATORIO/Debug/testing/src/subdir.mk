################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../testing/src/Employee.c \
../testing/src/addNodeTest.c \
../testing/src/addTest.c \
../testing/src/clearTest.c \
../testing/src/cloneTest.c \
../testing/src/containsAllTest.c \
../testing/src/containsTest.c \
../testing/src/deleteLinkedListTest.c \
../testing/src/getNodeTest.c \
../testing/src/getTest.c \
../testing/src/indexOfTest.c \
../testing/src/isEmptyTest.c \
../testing/src/lenTest.c \
../testing/src/main_test.c \
../testing/src/newTest.c \
../testing/src/popTest.c \
../testing/src/pushTest.c \
../testing/src/removeTest.c \
../testing/src/setTest.c \
../testing/src/sortTest.c \
../testing/src/subListTest.c 

C_DEPS += \
./testing/src/Employee.d \
./testing/src/addNodeTest.d \
./testing/src/addTest.d \
./testing/src/clearTest.d \
./testing/src/cloneTest.d \
./testing/src/containsAllTest.d \
./testing/src/containsTest.d \
./testing/src/deleteLinkedListTest.d \
./testing/src/getNodeTest.d \
./testing/src/getTest.d \
./testing/src/indexOfTest.d \
./testing/src/isEmptyTest.d \
./testing/src/lenTest.d \
./testing/src/main_test.d \
./testing/src/newTest.d \
./testing/src/popTest.d \
./testing/src/pushTest.d \
./testing/src/removeTest.d \
./testing/src/setTest.d \
./testing/src/sortTest.d \
./testing/src/subListTest.d 

OBJS += \
./testing/src/Employee.o \
./testing/src/addNodeTest.o \
./testing/src/addTest.o \
./testing/src/clearTest.o \
./testing/src/cloneTest.o \
./testing/src/containsAllTest.o \
./testing/src/containsTest.o \
./testing/src/deleteLinkedListTest.o \
./testing/src/getNodeTest.o \
./testing/src/getTest.o \
./testing/src/indexOfTest.o \
./testing/src/isEmptyTest.o \
./testing/src/lenTest.o \
./testing/src/main_test.o \
./testing/src/newTest.o \
./testing/src/popTest.o \
./testing/src/pushTest.o \
./testing/src/removeTest.o \
./testing/src/setTest.o \
./testing/src/sortTest.o \
./testing/src/subListTest.o 


# Each subdirectory must supply rules for building sources it contributes
testing/src/%.o: ../testing/src/%.c testing/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-testing-2f-src

clean-testing-2f-src:
	-$(RM) ./testing/src/Employee.d ./testing/src/Employee.o ./testing/src/addNodeTest.d ./testing/src/addNodeTest.o ./testing/src/addTest.d ./testing/src/addTest.o ./testing/src/clearTest.d ./testing/src/clearTest.o ./testing/src/cloneTest.d ./testing/src/cloneTest.o ./testing/src/containsAllTest.d ./testing/src/containsAllTest.o ./testing/src/containsTest.d ./testing/src/containsTest.o ./testing/src/deleteLinkedListTest.d ./testing/src/deleteLinkedListTest.o ./testing/src/getNodeTest.d ./testing/src/getNodeTest.o ./testing/src/getTest.d ./testing/src/getTest.o ./testing/src/indexOfTest.d ./testing/src/indexOfTest.o ./testing/src/isEmptyTest.d ./testing/src/isEmptyTest.o ./testing/src/lenTest.d ./testing/src/lenTest.o ./testing/src/main_test.d ./testing/src/main_test.o ./testing/src/newTest.d ./testing/src/newTest.o ./testing/src/popTest.d ./testing/src/popTest.o ./testing/src/pushTest.d ./testing/src/pushTest.o ./testing/src/removeTest.d ./testing/src/removeTest.o ./testing/src/setTest.d ./testing/src/setTest.o ./testing/src/sortTest.d ./testing/src/sortTest.o ./testing/src/subListTest.d ./testing/src/subListTest.o

.PHONY: clean-testing-2f-src

