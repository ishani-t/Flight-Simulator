# Executable names:
EXE = flights_sim
TEST = test

EXENAME = flight_sim
OBJS = main.o Parser.o Edge.o Flights.o Node.o BFS.o Map.o Dijkstra.o PNG.o HSLAPixel.o lodepng.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang version enforcement Makefile rule:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu")
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif

.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

Parser.o:  src/Parser.cpp
	$(CXX) $(CXXFLAGS) src/Parser.cpp

Node.o:  src/Node.cpp
	$(CXX) $(CXXFLAGS) src/Node.cpp

Edge.o:  src/Edge.cpp
	$(CXX) $(CXXFLAGS) src/Edge.cpp

Flights.o:  src/Flights.cpp
	$(CXX) $(CXXFLAGS) src/Flights.cpp

BFS.o:  src/BFS.cpp
	$(CXX) $(CXXFLAGS) src/BFS.cpp

Map.o:  src/Map.cpp
	$(CXX) $(CXXFLAGS) src/Map.cpp

Dijkstra.o:  src/Dijkstra.cpp
	$(CXX) $(CXXFLAGS) src/Dijkstra.cpp

PNG.o: cs225/PNG.cpp
	$(CXX) $(CXXFLAGS) cs225/PNG.cpp

HSLAPixel.o: cs225/HSLAPixel.cpp
	$(CXX) $(CXXFLAGS) cs225/HSLAPixel.cpp

lodepng.o: cs225/lodepng/lodepng.cpp
	$(CXX) $(CXXFLAGS) cs225/lodepng/lodepng.cpp

main.o : main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

test: output_msg catch/catchmain.cpp tests/bfs_test.cpp tests/dijkstra_test.cpp tests/parser_test.cpp tests/flights_test.cpp src/Edge.cpp src/Flights.cpp src/Node.cpp src/Parser.cpp
	$(LD) catch/catchmain.cpp tests/bfs_test.cpp tests/dijkstra_test.cpp tests/parser_test.cpp tests/flights_test.cpp src/Dijkstra.cpp src/Edge.cpp src/Flights.cpp src/Node.cpp src/Parser.cpp src/BFS.cpp $(LDFLAGS) -o test

clean:
	-rm -f *.o $(EXENAME) test