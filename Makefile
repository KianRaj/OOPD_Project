CXX = g++  # Compiler

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -Isrc -Iinclude -O2

# Linker flags
LDFLAGS = 

# Source files
SRCS = src/main.cpp \
       src/CommunicationPoint.cpp \
       src/Channel.cpp \
       src/DataPacket.cpp \
       src/Simulation.cpp \
       src/user.cpp \
       src/wifi4_communication.cpp \
       src/wifi5_communication.cpp \
       src/wifi6_communication.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXECUTABLE = wifi_simulator

# Default target
all: $(EXECUTABLE)

# Linking
$(EXECUTABLE): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

# Compiling
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f src/*.o $(EXECUTABLE)

# Phony targets
.PHONY: all clean