CXX = g++            
CXXFLAGS = -std=c++17 -lncurses 
TARGET = exe       

SRCS = main.cpp converter.cpp

all: $(TARGET)

clean:
	rm $(TARGET)


$(TARGET): $(SRCS)
	$(CXX) $(SRCS) -o $@ $(CXXFLAGS)


#OS := $(shell uname)
#ifeq ($(OS), Windows_NT)
# do Windows compilation
#else
# do Unix compilation
#endif
