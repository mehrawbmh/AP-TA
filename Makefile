CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -O2

SRCS = main.cpp command_manager.cpp gate.cpp wire.cpp and_gate.cpp base_module.cpp or_gate.cpp not_gate.cpp
OBJS = $(SRCS:%.cpp=bin/%.o)

DEPS = wire.hpp base_module.hpp gate.hpp command_manager.hpp and_gate.hpp or_gate.hpp not_gate.hpp exceptions.hpp

TARGET = ModelSim.out

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

bin/%.o: %.cpp $(DEPS)
	@mkdir -p bin  # Ensure the bin directory exists
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET)
	rm -rf ./bin
	rm -f  *.gch

.PHONY: all clean
