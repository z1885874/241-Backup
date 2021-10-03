#
# PROGRAM:    Quiz 5
# PROGRAMMER: Kurt McMahon
# LOGON ID:   t90kjm1
#

# Compiler variablesa
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11 -g

# Rule to link object code files to create executable file
quiz5: quiz5.o
	$(CXX) $(CXXFLAGS) -o quiz5 quiz5.o

# Rules to compile source code files to object code
quiz5.o: quiz5.cpp

# Pseudo-target to remove object code and executable files
clean:
	rm -f *.o quiz5
