CXX = clang++
CXXFLAGS = '-std=c++14' '-g'
LDLIBS = '-lSDL2'
objects = string.o vector.o main.o
binary = string

all: $(objects)
	$(CXX) -o $(binary) $(objects) $(LDLIBS)

clean:
	rm $(binary) $(objects)
