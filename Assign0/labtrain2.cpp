
#
# PROGRAM: Lab Training Exercise
# AUTHOR:  your name
#

CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

labtrain: labtrain.o
	$(CXX) $(CXXFLAGS) -o labtrain labtrain.o

labtrain.o: labtrain.cpp

clean:
	rm -f *.o labtrain
