# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -Wall -std=c++11
# Source files
SRC := $(wildcard *.cpp Resources/*.cpp Utilities/*.cpp)
# Object files
OBJ := $(SRC:.cpp=.o)
# Output executable name
TARGET := main

# Default target
all: $(TARGET)

# Link all object files to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJ) $(TARGET)

# PHONY to avoid conflicts with file names
.PHONY: all clean
