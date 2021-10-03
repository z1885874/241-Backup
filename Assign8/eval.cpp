/*

eval.cpp
CSCI 241 Assign8

Created by Christopher Huguelet (z1885874)
Section 2

*/
#include "eval.h"
/**
 * checks if thier is bianary operators
 * @param op, the string were input into the function
 * @returns true or false if binary operator or not
 **/


bool isbin(const std::string& op)
{
	if (op[0] == '~')
	{
		return false;
	}
	else
	{
		return true;
	}
}

/**
 * converts a string into an integer
 * @param con, the string to be converted.
 * @returns the integer returning from the strong
 **/

int stringtoint(const std::string& con)
{
	if (isalpha(con[0]))
	{
		return con[0] - 'a';
	}
	else
	{
		return stoi(con);
	}
	
}


/**
 * performs calculations
 * @param l, the leftmost numerator
 * @param r, the rightmost numerator
 * @param o, the string containing the operator
 * @return integer, retruns the calcualtion of r and k
 **/
 
int calculate(int l, int r, std::string& o)
{
	switch(o[0])
	{
		case'+': return l + r;
		case'-': return l - r;
		case'*': return l * r;
		case'/': return l / r;
		case'^': return std::pow(l,r);
		default: return 0;
	}
}

/**
 * Evaluates the numbers down to a singlular output
 * @param input, the string being input into the value.
 * @returns integer post evaluation and calculation
 **/

int evaluate(const std::string& input)
{
	std::string op;
	std::stringstream ss(input);
	mystack opstack;
	while (ss>>op)
	{
		if (isoperator(op[0]))
		{
			if (isbin(op))
			{
				int r = opstack.top();
				opstack.pop();
				int l = opstack.top();
				opstack.pop();
				if(r == 0 && op[0] == '/')
				{
				std::cout<< "*** Division by 0 ***" << std::endl;
				return 0;
			    }
			    opstack.push(calculate (l, r, op));   
			}else
			{
				int r = opstack.top();
				opstack.pop();
				opstack.push(-r);
			}	    
		}
		else
		{
			opstack.push(stringtoint(op));
		}
	}
return opstack.top();
}


