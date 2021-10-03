/*

scc.cpp
CSCI 241 Assign9

Created by Christopher Huguelet (z1885874)
Section 2
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <sstream>
#include "sml.h"
#include <algorithm>
#include "inpost.h"
using namespace std;

/**
 * 
 * Symbol table entry.
 *
 ********************************************************************/
struct table_entry
{
    int symbol;
    char type;        // 'C' constant, 'L' Simple line number, 'V' variable
    int location;     // Simplesim address (00 to MEMSIZE-1)
    table_entry(int symbol = 0, char type = 'L', int location = -1)
    {
	this->symbol = symbol;
	this->type = type;
	this->location = location;
	}
	table_entry& operator=(const table_entry& entry)
	{
	this->symbol = entry.symbol;
	this->type = entry.type;
	this->location = entry.location;
	return *this;	
	}
};

/**
 * 
 * Simple compiler.
 *
 ********************************************************************/
class scc
{
public:

    // Data members
    static const int MEMORY_SIZE = 100;
    static const int SYMBOL_TABLE_SIZE = 1000;

    // Member functions
    scc();
    void first_pass();
    void second_pass();
    void print_program() const;

private:

    // Data members
    int memory[MEMORY_SIZE];
    
    int data[MEMORY_SIZE];
    int ndata = 0;

    table_entry symbol_table[SYMBOL_TABLE_SIZE];
    
    int flags[MEMORY_SIZE];

    int next_instruction_addr = 0;
    int next_const_or_var_addr = MEMORY_SIZE - 1;
    int next_symbol_table_idx = 0;
    
    int nextStackIndex = 0;

    // Member functions
    void data_check() const;
    void memory_check() const;
    void stack_check(int) const;
    void handle_input(istringstream&);
    void handle_data(istringstream&);
    void handle_print(istringstream&);
    void handle_goto(istringstream&);
    void handle_if_goto(istringstream&);
    void handle_let( string&);
    void handle_end();
    int get_symbol_location(const string&);
    int search_symbol_table(int, char) const;
    void pushToStack();
    void topStack();
    void popStack();
};

int main()
{
    scc compiler;

    compiler.first_pass();

    compiler.second_pass();

    compiler.print_program();

    return 0;
}

/**
 * Initializes memory and flags array.
 *
 ********************************************************************/
scc::scc()
{
    // Initalize memory and flags arrays.
    for (int i = 0; i < MEMORY_SIZE; i++)
    {
        memory[i] = 7777;
        flags[i] = -1;
    }
}

/**
 * Performs first pass of compilation.
 *
 ********************************************************************/
void scc::first_pass()
{
    string buffer1, buffer2, command;

    int line_number;

    while (getline(cin, buffer1))
    {
        buffer2 = buffer1;
        istringstream ss(buffer1);

        ss >> line_number;


        symbol_table[next_symbol_table_idx].symbol = line_number;
        symbol_table[next_symbol_table_idx].type = 'L';
        symbol_table[next_symbol_table_idx].location = next_instruction_addr;
        next_symbol_table_idx++;

        // Extract the command from this Simple statement.
        ss >> command;

        // Process the command.
        if (command == "input")
        {
            handle_input(ss);
        }
        else if (command == "data")
        {
            handle_data(ss);
        }
        else if (command == "let")
        {
            handle_let(buffer2);
        }
        else if (command == "if")
        {
            handle_if_goto(ss);
        }
        else if (command == "goto")
        {
            handle_goto(ss);
        }
        else if (command == "print")
        {
            handle_print(ss);
        }
        else if (command == "end")
        {
            handle_end();
        }
        else // if (command == "rem")
        {
            // Nothing to do for this instruction.
        }
    }
}

/**
 * Generates code for an "input" instruction.
 *
 * @param ss Input string stream from which to read.
 *
 ********************************************************************/
void scc::handle_input(istringstream& ss)
{
    string token;

    ss >> token;

    int location = get_symbol_location(token);

    memory_check();
    memory[next_instruction_addr] = READ * 100 + location;
    next_instruction_addr++;
}

/**
 * Generates code for a "data" instruction.
 *
 * @param ss Input string stream from which to read.
 *
 ********************************************************************/
void scc::handle_data(istringstream& ss)
{
    string token;

    ss >> token;

    data_check();
    data[ndata] = stoi(token);
    ndata++;
}

/**
 * Generates code for an "end" instruction.
 *
 ********************************************************************/
void scc::handle_end()
{
    memory_check();
    memory[next_instruction_addr] = HALT * 100;
    next_instruction_addr++;
}


/**
 * Generates code for an "print" instruction.
 *
 * @param ss Input string stream from which to read.
 *
 ********************************************************************/
void scc::handle_print(istringstream& ss)
{
   string token;

    ss >> token;

    int location = get_symbol_location(token);

    memory_check();
    memory[next_instruction_addr] = WRITE * 100 + location;
    next_instruction_addr++;
}

/**
 * Generates code for an "goto" instruction.
 *
 * @param ss Input string stream from which to read.
 *
 ********************************************************************/
void scc::handle_goto(istringstream& ss)
{
string token = "";
ss >> token;

int line = stoi(token);
int sym_index = search_symbol_table(line, 'L');
memory_check();
memory[next_instruction_addr] = BRANCH * 100;
if (sym_index == -1)
{
    flags[next_instruction_addr] = line;	
}
else
{
    memory[next_instruction_addr] += symbol_table[sym_index].location;	
}
next_instruction_addr++;

}

/**
 * Generates code for an "if_goto" instruction.
 *
 * @param ss Input string stream from which to read.
 *
 ********************************************************************/
void scc::handle_if_goto(istringstream& ss)
{
string lhs;
string op;
string rhs;
string line_number;
ss >> lhs >> op >> rhs >> line_number >> line_number;
int l_index = get_symbol_location(lhs);
int r_index = get_symbol_location(rhs);
memory_check();
memory[next_instruction_addr] = (LOAD*100 + (op[0]=='>'?r_index:l_index));
next_instruction_addr++;
memory_check();
memory[next_instruction_addr] =(SUBTRACT*100 + (op[0]!='>'?r_index:l_index));
next_instruction_addr++;
if(op[0]=='!')
{
	memory_check();
	memory[next_instruction_addr] = BRANCHZERO*100 + next_instruction_addr + 2;
	next_instruction_addr++;
	memory_check();
	memory[next_instruction_addr] = BRANCH*100;
	int index = search_symbol_table(stoi(line_number), 'L');
	if(index == -1)
	{
		flags[next_instruction_addr] = stoi(line_number);
	}
	else
	{
		memory[next_instruction_addr] += symbol_table[index].location;
	}
	next_instruction_addr++;
}
else
{
    if(op[0] != '=')
    {
	memory_check();
	memory[next_instruction_addr] = BRANCHNEG*100;
	int index = search_symbol_table(stoi(line_number), 'L');
	if(index == -1)
	{
		flags[next_instruction_addr] = stoi(line_number);
	}
	else
	{
		memory[next_instruction_addr] += symbol_table[index].location;
	}
	next_instruction_addr++;

	}
	if(op[1] == '=')
	{
		memory_check();
	memory[next_instruction_addr] = BRANCHZERO*100;
	int index = search_symbol_table(stoi(line_number), 'L');
	if(index == -1)
	{
		flags[next_instruction_addr] = stoi(line_number);
	}
	else
	{
		memory[next_instruction_addr] += symbol_table[index].location;
	}
	next_instruction_addr++;
	}	
}
}

/**
 * Generates code for an "let" instruction.
 *
 * @param ss Input string stream from which to read.
 *
 ********************************************************************/
void scc::handle_let( string& buffer)
{
    memory_check();
    string sresult = "";
    istringstream ss(buffer);
    ss >> sresult >> sresult >> sresult;
    int result = get_symbol_location(sresult);



    
	buffer.erase(buffer.begin(), find(buffer.begin(), buffer.end(), '=')+1);
    buffer = convert(buffer);
    string token = "";
    ss = istringstream(buffer);
    ss >> token;
    while(ss)
    {
        if(!isoperator(token[0]))
        {
        int oplocation = get_symbol_location(token);
        memory_check();
        memory[next_instruction_addr] = LOAD * 100 + oplocation;
        next_instruction_addr++;
        pushToStack();
        } 
        else 
        {
	char op = token[0];
    topStack();
    popStack();
    switch(op)
    {
        case '+':
        case '*':
        memory_check();
        memory[next_instruction_addr] = (op=='+' ? ADD : MULTIPLY) * 100;
        flags[next_instruction_addr] = -2 - nextStackIndex;
        next_instruction_addr++;
            popStack();
            break;        
        case '-':
        case '/':
            //if -,/ store accumulator to temporary storage
            memory_check();
            memory[next_instruction_addr] = STORE * 100;
            flags[next_instruction_addr] = -2;
            next_instruction_addr++;
            //load top to accumulator
            topStack();
            //pop
            popStack();
            
            memory_check();
            memory[next_instruction_addr] = (op=='-' ? SUBTRACT : DIVIDE) * 100;
            flags[ next_instruction_addr] = -2;
            next_instruction_addr++;
            break;
    }
    //push operator result to stack
    pushToStack();
        }
    ss >> token;
    }
    topStack();
    memory_check();
            memory[next_instruction_addr] = STORE * 100 + result;
            next_instruction_addr++;
    popStack();
}

/**
 * Checks whether there is room in the data array to add another data
 * item.
 *
 ********************************************************************/
void scc::data_check() const
{
    if (ndata >= MEMORY_SIZE)
    {
        cout << "*** ERROR: too many data lines ***\n";
        exit(1);
    }
}

/**
 * Checks whether there is room in the memory array to add another
 * instruction.
 *
 ********************************************************************/
void scc::memory_check() const
{
    if (next_instruction_addr >= MEMORY_SIZE || next_instruction_addr >
        next_const_or_var_addr)
    {
        cout << "*** ERROR: ran out Simplesim memory ***\n";
        exit(1);
    }
}
/**
 * Checks whether there is room in the memory to add another stack 
 * element.
 ********************************************************************/
void scc::stack_check(int index) const
{
    if (next_instruction_addr >= next_const_or_var_addr + index)
    {
        cout << "*** ERROR: insufficient stack space ***" << endl;
        exit(1);
    }
}

/**
 * Gets the location of a constant or variable, adding it to the 
 * symbol table and memory if necessary.
 *
 * @param token The symbol to locate.
 *
 * @return The symbol's location.
 *
 ********************************************************************/
int scc::get_symbol_location(const string& token)
{
    int location, symbol;
    char type;

    if (islower(token[0]))
    {
        // This is a variable.
        symbol = token[0];
        type = 'V';
    }
    else
    {
        // This is an integer constant.
        symbol = stoi(token);
        type = 'C';
    }

    int index = search_symbol_table(symbol, type);
    if (index == -1)
    {
        // Symbol is not in symbol table.
        // Add this symbol to the symbol table.
        location = next_const_or_var_addr;

        symbol_table[next_symbol_table_idx].symbol = symbol;
        symbol_table[next_symbol_table_idx].type = type;
        symbol_table[next_symbol_table_idx].location = location;
        next_symbol_table_idx++;
        
        // Allocate memory for this constant or variable.
        memory_check();
        if (type == 'V')
            memory[next_const_or_var_addr] = 0;
        else
            memory[next_const_or_var_addr] = symbol;

        next_const_or_var_addr--;
    }
    else
    {
        // Symbol is in symbol table at index.
        location = symbol_table[index].location;
    }

    return location;
}

/**
 * Searches the symbol table for a symbol.
 *
 * @param symbol The symbol for which to search the symbol table.
 * @param type The type of the symbol ('C', 'L', or 'V')
 *
 * @return The index of the item found or -1 if the search fails.
 *
 * @note Uses the linear search algorithm.
 *
 ********************************************************************/
int scc::search_symbol_table(int symbol, char type) const
{
    for (int i = 0; i < next_symbol_table_idx; i++)
    {
        if (symbol == symbol_table[i].symbol && type == symbol_table[i].type)
            return i;
    }

    return -1;
}

/**
 * Performs second pass of compilation.
 *
 ********************************************************************/
void scc::second_pass()
{
	for(int i = 0; i < MEMORY_SIZE; i++)
	{
		if (flags[i] != -1)
		{
			if (flags[i] >= 0)
			{
				memory[i] += symbol_table[search_symbol_table(flags[i], 'L')].location;
			}
            else if (flags[i] == -2)
            {
                memory[i] += next_const_or_var_addr;
            }
            else
            {
                stack_check(flags[i] + 2);
                memory[i] += next_const_or_var_addr + flags[i] + 2;
            }
		}
	}
}

/**
 * Prints memory and data for the compiled SML program.
 *
 ********************************************************************/
void scc::print_program() const
{
    cout << setfill('0') << internal << showpos;

    // Print entire memory array.
    for (int i = 0; i < MEMORY_SIZE; i++)
        cout << setw(5) << memory[i] << endl;

    // Print "end of instructions" sentinel value.
    cout << -99999 << endl;

    cout << setfill(' ') << noshowpos;
    
    // Print data values.
    for (int i = 0; i < ndata; i++)
        cout << data[i] << endl;
}

/**
 * Stores the accumulator on top of program stack
**/
void scc::pushToStack()
{
    //store accumulator on the program's stack
    memory_check();
    memory[next_instruction_addr] = STORE * 100;
    flags[next_instruction_addr] = -3 - nextStackIndex;
    nextStackIndex++;
    next_instruction_addr++;
}

/**
 * Loads top of program stack to accumulator
**/
void scc::topStack()
{
    //load program stack top to accumulator
    memory_check();
    memory[next_instruction_addr] = LOAD * 100;
    flags[next_instruction_addr] = -2 - nextStackIndex;
    next_instruction_addr++;
}

/**
 * Pops the program stack
**/
void scc::popStack()
{
    //decrement program stack size
    nextStackIndex--;
}
