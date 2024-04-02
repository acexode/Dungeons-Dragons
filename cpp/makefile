CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic
INCLUDES = -I./include

SRC_DIR = ./src
INC_DIR = ./include

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,%.o,$(SRCS))

EXECUTABLE = dungeon-explorer

$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXECUTABLE)

.PHONY: clean
