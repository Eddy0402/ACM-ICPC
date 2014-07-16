CODE = $(wildcard *.cpp)
TARGET= $(CODE:.cpp=)

all : $(TARGET)

% : %.cpp
	g++ -g -O3 -std=c++11 -Wall -o $@ $<
