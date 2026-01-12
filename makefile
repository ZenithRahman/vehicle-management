# 1. Variables
CXX = g++
# -std=c++20/23 is recommended for projects in 2026
CXXFLAGS = -Wall -Wextra -g -std=c++20 
TARGET = main
SRCS = main.cpp mainmenu.cpp vehicle.cpp
OBJS = $(SRCS:.cpp=.o)

# Detect OS for cross-platform 'clean' and executable naming
ifeq ($(OS),Windows_NT)
    RM = del /Q
    TARGET_EXE = $(TARGET).exe
    RUN_CMD = $(TARGET_EXE)
else
    RM = rm -f
    TARGET_EXE = $(TARGET)
    RUN_CMD = ./$(TARGET)
endif

# 2. Phony Targets (Prevents conflict with files named 'all', 'clean', or 'run')
.PHONY: all run clean

# 3. Rules
all: $(TARGET_EXE)

# Link object files into the target executable
$(TARGET_EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET_EXE) $(OBJS)

# Compile .cpp files into .o files using pattern matching
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build and execute the program
run: $(TARGET_EXE)
	$(RUN_CMD)

# Cleanup generated files safely across platforms
clean:
	$(RM) $(TARGET_EXE) $(OBJS)
