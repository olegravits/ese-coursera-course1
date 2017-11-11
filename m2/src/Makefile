#/******************************************************************************
# * Copyright (C) 2017 by Oleg Ravits
# *
# * Redistribution, modification or use of this software in source or binary
# * forms is permitted as long as the files maintain this copyright. Users are 
# * permitted to modify this and use it to learn about the field of embedded
# * software. Oleg Ravits are not liable for any misuse of this material. 
# *
# *****************************************************************************/

#------------------------------------------------------------------------------
# makefile support two platforms:
#      the host environment and the target embedded system MSP432
#
# Use: make [TARGET] [PLATFORM=OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      <FILE>.i - Builds <FILE>.i preprocessed output file
#      <FILE>.asm - Builds <FILE>.s assembly file
#      <FILE>.dep - Builds <FILE>.d dependency file
#
#      compile-all - Compile all object files, but DO NOT link
#      build - Builds and links all source files
#      all - Same as build
#      clean - removes all generated files
#
# Platform Overrides:
#      HOST - native compiling
#      MSP432 - cross compiling
#
#------------------------------------------------------------------------------

include sources.mk

# Platform Overrides
PLATFORM = 
TARGET = c1m2

ifeq ($(PLATFORM),HOST)
CC = gcc
LD = ld
LDFLAGS = -Wl,-Map=$(TARGET).map
CFLAGS = -Wall -std=c99 -Werror -O0 -g
CPPFLAGS = -DHOST
INCLUDES = -I ../include/common/
SRCS = memory.c main.c
endif


ifeq ($(PLATFORM),MSP432)
# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

# Compiler Flags and Defines
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
CFLAGS = -Wall -std=c99 -Werror -O0 -g -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS)
CPPFLAGS = -DMSP432
INCLUDES = -I ../include/common/ \
	-I ../include/msp432/ \
	-I ../include/CMSIS/	
SRCS = memory.c main.c interrupts_msp432p401r_gcc.c startup_msp432p401r_gcc.c system_msp432p401r.c
endif

OBJS = $(SRCS:.c=.o)

%.i : %.c
	$(CC)  $< $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -E -o $@

%.asm : %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -S 

%.dep : %.c
	$(CC) -c $^ $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -MD   

%.o : %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -o $@

.PHONY: compile-all
compile-all: $(SRCS) 
	$(CC) -c $^ $(CPPFLAGS) $(CFLAGS) $(INCLUDES)

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDES) -o $@ $^

#.PHONY: debug
#debug: $(TARGET).dbg

#$(TARGET).dbg: $(OBJS)
#	$(CC) -g $(CFLAGS) $(LDFLAGS) $(INCLUDES) -o $@ $^

.PHONY: clean
clean :
	rm -f $(TARGET).out $(TARGET).map *.o *.i *.s *.d

