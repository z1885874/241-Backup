#
# PROGRAM:    Assignment 9
# PROGRAMMER: your name
# LOGON ID:   your z-id
# DATE DUE:   due date of program
#
    
# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11 -g
        
# Rule to link object code files to create executable file
all: assign12

assign12: assign12.o shape.o rectangle.o triangle.o circle.o
	$(CXX) $(CXXFLAGS) -o assign12 $^

# Rules to compile source code file to object code
assign12.o: assign12.cpp
shape.o: shape.h shape.cpp 
rectangle.o: rectangle.h rectangle.cpp
triangle.o: triangle.h triangle.cpp
circle.o: circle.h circle.cpp

# Pseudo-target to remove object code and executable files
clean:
	rm -f assign12 *.o
