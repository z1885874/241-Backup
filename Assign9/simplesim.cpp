/*CSCI 241       Assignment 4   Spring 2021
Programmer: Christopher Huguelet
Section: 2
Date Due: 2/15/2021
Purpose: this program is created in order to simulate a simple computer called simplesim
*/

#include <iostream>
#include <iomanip>
#include "sml.h"
#include "simplesim.h"

using namespace std;
/**
 *
 * Default constructor
 *
 * @note Sets all memory locations to +7777
 * 
 **/
simplesim::simplesim()
{
    accumulator = 0;
    instruction_counter = 0;
    instruction_register = 0;
    operation_code = 0;
    operand = 0;
    for(int i = 0; i < 100; i++)
    {
		memory[i] = 7777;
	}
}
/**
 *
 * Load Program from standard input to memory
 * @return true if sucessfully loaded, returns false if error.
 * 
 * @note Error message "pgm too large" :Program will fail in this step of the program is too large with  
 * @note Error message "invalid word" :program will fail due to an invalid word being loaded
 **/
bool simplesim::load_program()
{
	int read_val = 0;
	int mem_loc = 0;
	while (cin >> read_val)
	{
		if (read_val == -99999)
		{
			return true;
		}
	if (mem_loc >= 100)
	{
		cout << "*** ABEND: pgm load: pgm too large ***" << endl;
		return false;
	}
	if (read_val < -9999 || read_val > 9999)
	{
		cout << "*** ABEND: pgm load: invalid word ***" << endl;
		return false;
	}
	memory[mem_loc] = read_val;
	mem_loc++;
	}
return false;	
}
/**
 *
 * Executes program based upon input.
 * 
 * @note Error message "Adressibility error" :Program will fail in this step of the program is many data entries long
 * @note Error message "illegal input" :Program will fail if it is outside established boundaries of 9999 and -9999
 * @note Error message "Invalid Opcode" :Operation code does not fit within the program
 * @note Error message "attempt to divide by zero" :You have commited a great sin and attempted to end the world. (In reality, you have performed an invalid operation and will not compute)
 * @note Error message "underflow" : Executed program went below defined boundary of -9999
 * @note Error message "overflow" : Executed program went above defined boundary of 9999
 * */
void simplesim::execute_program()
{
	bool done = false;
	while (!done)
	{
		if (instruction_counter == 100)
		{
			cout << "*** ABEND: addressability error ***" << endl;
			return;
        }
        instruction_register = memory[instruction_counter];
        operation_code = instruction_register/100;
        operand = instruction_register%100;
        int input = 0;
        bool branch = false;
        switch(operation_code){
		case READ: //Reads a word from standard input, performs error checking, puts valid word into specified memory adresses.
			cin >> input;
			if(input < -9999 || input > 9999)
        {
            cout << "*** ABEND: illegal input ***" << endl;
            return;
        }
			cout << "READ: " << internal << setfill('0') << showpos << setw(5) << input << endl;
            cout << right << setfill(' ') << noshowpos;
            memory[operand] = input;
            
			break;

		case WRITE: //Writes the memory stored at specified memory location
            cout << internal << setfill('0') << showpos;
            cout << setw(5) << memory[operand] << endl;
            cout << right << setfill(' ') << noshowpos;
			break;

		case STORE: //Copies accumulator to the specified memory location
			memory[operand] = accumulator;
			break;
			
		case LOAD: // copies specified memory location to accumulator
			accumulator = memory[operand];
			break;
			
		case ADD: //Performs addition with specified memory lcoation and accumulator, checks for underflow and overflow.
			if (accumulator + memory[operand] > 9999)
			{
				cout << "*** ABEND: overflow ***" << endl;
				return;
			}
			if (accumulator + memory[operand] < -9999)
			{
				cout << "*** ABEND: underflow ***" << endl;
				return;
			}
			accumulator += memory[operand];
			break;
		case SUBTRACT: //Performs subtraction with specified memory lcoation and accumulator, checks for underflow and overflow.
			if (accumulator - memory[operand] > 9999)
			{
				cout << "*** ABEND: overflow ***" << endl;
				return;
			}
			if (accumulator - memory[operand] < -9999)
			{
				cout << "*** ABEND: underflow ***" << endl;
				return;
			}
			accumulator -= memory[operand];
			break;
			
		case MULTIPLY: //Performs multiplication with specified memory lcoation and accumulator, checks for underflow and overflow.
			if (accumulator * memory[operand] > 9999)
			{
				cout << "*** ABEND: overflow ***" << endl;
				return;
			}
			if (accumulator * memory[operand] < -9999)
			{
				cout << "*** ABEND: underflow ***" << endl;
				return;
			}
			accumulator *= memory[operand];
			break;
			
		case DIVIDE: //Performs division with specified memory lcoation and accumulator, checks for dividing by zero
			if (memory[operand] == 0)
			{
				cout << "*** ABEND: attempted division by 0 ***" << endl;
				return;
			}
			accumulator /= memory[operand];
			break;
			
		case BRANCH: //jumps to specified memory address
			branch = true;
			instruction_counter = operand;
			break;
			
		case BRANCHZERO: //if accumulator is zero, jumps to specified memory address
		if (accumulator == 0)
		{
			branch = true;
			instruction_counter = operand;
		}
			break;
			
			case BRANCHNEG: //if accumulator is less than zero, jumps to specified memory address
		if (accumulator < 0)
		{
			branch = true;
			instruction_counter = operand;
		}
			break;
			
		case HALT: //program will cease here, having executed without errors.
			cout << "*** Simplesim execution terminated ***" << endl;
			done = true;
			break;

		default: //Program will default here if nothing happens, and no other errors are triggered.
			cout << "*** ABEND: invalid opcode ***" << endl;
			return;
			break;
		}
	if (!done && !branch)
	{
		instruction_counter++;
	}
}
}
/**
 * Dumps memory and register contents to standard output.
**/
void simplesim::dump() const
{
	cout << "REGISTERS:" << endl <<
	left << setfill(' ') << setw(24) <<
	"accumulator: " << 
	showpos << internal << setfill('0') << setw(5) <<
	accumulator << endl <<
	left << setfill(' ') << setw(24) <<
	"instruction_counter: " << 
	right << noshowpos << setfill('0') << setw(2) <<
	instruction_counter << endl <<
	left << setfill(' ') << setw(24) <<
	"instruction_register: " << 
	showpos << internal << setfill('0') << setw(5) <<
	instruction_register << endl <<
	left << setfill(' ') << setw(24) <<
	"operation_code: " << 
	right << noshowpos << setfill('0') << setw(2) <<
	operation_code << endl <<
	left << setfill(' ') << setw(24) <<
	"operand: " <<
	right << noshowpos << setfill('0') << setw(2) <<
	operand << endl << endl << 
	"MEMORY:" << endl <<
	"  ";
	for(int j = 0; j < 10; j++)
	{
		cout << noshowpos << right << setfill(' ') << setw(6) << j;
	}
	cout << endl;
    for(int row = 0; row<10; row++)
    {
		cout << noshowpos << right << setfill(' ') << setw(2) << row*10;
        for(int col = 0; col < 10; col++)
        {  
            cout << " " << showpos << internal << setfill('0') << setw(5) << memory[(10*row)+col];
        } 
    cout << endl;
    }
}
    

