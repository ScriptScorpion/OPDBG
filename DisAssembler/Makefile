CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -lncurses -O1
TARGET := asmdump

SRCS := main.cpp converter.cpp

$(TARGET): $(SRCS)
	$(CXX) $(SRCS) -o $@ $(CXXFLAGS)