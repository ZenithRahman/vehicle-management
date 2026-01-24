# Variables
CC = gcc
CFLAGS = -Wall -Wextra -g -std=c11
TARGET = main
SRCS = main.c mainmenu.c vehicle.c
OBJS = $(SRCS:.c=.o)

# Detect OS
ifeq ($(OS),Windows_NT)
    RM = del /Q
    TARGET_EXE = $(TARGET).exe
    RUN_CMD = $(TARGET_EXE)
else
    RM = rm -f
    TARGET_EXE = $(TARGET)
    RUN_CMD = ./$(TARGET)
endif

.PHONY: all run clean

all: $(TARGET_EXE)

$(TARGET_EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET_EXE) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET_EXE)
	$(RUN_CMD)

clean:
	$(RM) $(TARGET_EXE) $(OBJS)
