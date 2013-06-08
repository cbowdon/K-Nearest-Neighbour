CXX = c++
CXXFLAGS = -std=c++11 -stdlib=libc++ -Wall #-g
LDFLAGS = -I include

MAIN = src/main.cpp
ASSEMBLIES = KNN.o


vpath %.hpp include include/test
vpath %.cpp src src/test

%.o: %.cpp %.hpp
	$(CXX) -c $< $(CXXFLAGS) $(LDFLAGS) -o $@

all: $(MAIN) $(ASSEMBLIES)
	ctags -R .
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^

run: all
	./a.out
