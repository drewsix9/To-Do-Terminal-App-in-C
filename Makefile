# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source files
SRCS = main.cpp database.cpp printables.cpp filehandling.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable
TARGET = myapp

# Default target
all: $(TARGET)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link object files into the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
