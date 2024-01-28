CXX = g++
CXXFLAGS = -g -Wall -Weffc++ -std=c++11
INCLUDES = -Iinclude

SRCS = $(wildcard ./src/*.cpp)
OBJS = $(patsubst ./src/%.cpp, ./bin/%.o, $(SRCS))
TARGET = ./bin/warehouse

all: clean compile link cleanObjAndRun

compile: $(OBJS)

./bin/%.o: ./src/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

link: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(TARGET) ./bin/*.o

cleanObjAndRun:
	rm -f ./bin/*.o