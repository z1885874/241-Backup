/*CSCI 241       Assignment 2   Spring 2021
Programmer: Christopher Huguelet
Section: 2
Date Due: 1/28/2021
Purpose: this program is created in order to provide a solution to the tower of hanoi issue.
A bit of odd things with this program, I initially made it work with the two pegs, the temp and the dest peg, inversed.
*/
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>


using std::cout;
using std::endl;
using std::stoi;

void move (int, int, int, int);

int main(int argc, char* argv[])
{
    int n_disks;  //checks for command specifying how many disks there are to move
    
    if (argc == 1)
    {
	    cout << "missing arguement\n" 
	         << "Usage: hanoi number-of-disks\n";
	    exit(1);
	}
	
	for (int i = 0; argv[1][i] != '\0'; i++) //makes sure arguement is a number
	{
	    if (!isdigit(argv[1][i]))
	    {
			cout << "Arguement must be a number\n"
			     << "Usage: hanoi number-of-disks\n";
			exit(1);
	    }
	}
	
	n_disks = stoi(argv[1]); //convert to interger
	
	move(n_disks, 1, 2, 3);
	
	return 0;
}

void move (int n_disks, int src_peg, int dest_peg, int temp_peg) //moves all disks with this program
{
    if (n_disks >= 1)
    {
        move(n_disks - 1, src_peg, temp_peg, dest_peg);
        cout << n_disks << " " << src_peg << "->" << dest_peg << endl; 
        move(n_disks - 1, temp_peg, dest_peg, src_peg);
    }
}
    
