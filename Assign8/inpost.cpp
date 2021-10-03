#include "inpost.h"
/**
 * test if a character is an operator.
 * @param c character to be tested
 * @return true if operator, fasle if not 
 **/

bool isoperator (const char c)
{
	switch(c)
	{
		case '-' :
		case '+' :
		case '/' :
		case '*' :
		case '^' :
		case '~' :
		    return true;
		default :
		    return false;
		     
     }
}

/**
 * gets precedence for operators
 * @param c the character to be evaluated
 * @return precendence of operator, -1 if not operator
 **/
 
int precedence (const char c)
{
	switch(c)
	{
		case '-' :
		case '+' :
		    return 1;
		case '/' :
		case '*' :
		    return 2;
		case '^' :
		case '~' :
		    return 3;
		default :
		    return -1;
	}	     
}

/**
 * converts a string from infix to postfix notation
 * @param input string in infix notation.
 * @returns output is string in post fix notation
 **/

std::string convert(const std::string& input)
{
	std::string output; 
	mystack opstack;
	for (size_t i = 0; i < input.length(); i++)  
	{
		const char c = input[i];
		if (isspace(c));
	    else if (c == '(')
		    {
			opstack.push(c);
		    }
		else if (isalnum(c))
		{
			if (output.length() > 0)
			{
				output += ' ';
			}
				output += c;
				while(isalnum(input[i+1]))
				{
					i++;
					output += input[i];
				}
			}
		
		else if (isoperator(c))
		{
			while  (!(opstack.empty())&& precedence(opstack.top())>=precedence(c))
			{
				output += ' ';
				output += opstack.top();
				opstack.pop();
			}
			opstack.push(c);
		}
		else if (c == ')')
		{
		    while (opstack.top() != '(')
		    {
				output += ' ';
				output += opstack.top();
				opstack.pop();
			}
			opstack.pop();
	    }
	}
    while (!(opstack.empty()))
    {
		output += ' ';
	    output += opstack.top();
	    opstack.pop();
	}
return output;}
