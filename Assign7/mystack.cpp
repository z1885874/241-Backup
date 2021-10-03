#include "mystack.h"

/**
 * default contructor
 **/
mystack::mystack()
{
	sap = nullptr;
	stackcap = 0;
	stacksize = 0;
}

/**
 * copy constructor
 **/

mystack::mystack(const mystack& x)
{
	stackcap = x.stackcap;
	stacksize = x.stacksize;
	if (stackcap == 0)
	{
		sap = nullptr;
	}
	else
	{
		sap = new char[stackcap];
		for (size_t i = 0; i < stacksize; i++)
		{
			sap[i] = x.sap[i];
		}
	}
	
	
}

/**
 * destructor
 **/

mystack::~mystack()
{
	delete[] sap;
}

/**
 * copy assignment
 **/

mystack& mystack::operator= (const mystack& x)
{
	if (&x != this)
	{
		delete[] sap;
		stackcap = x.stackcap;
	    stacksize = x.stacksize;
	if (stackcap == 0)
	{
		sap = nullptr;
	}
	else
	{
		sap = new char[stackcap];
		for (size_t i = 0; i < stacksize; i++)
		{
			sap[i] = x.sap[i];
		}
	}
		
}
return *this; }

/**
 * capacity getter
 **/

size_t mystack::capacity() const
{
    return stackcap;
}

/**
 * size getter
 **/

size_t mystack::size() const
{
	return stacksize;
}

/**
 * empty flag
 **/

bool mystack::empty() const
{
	return stacksize == 0;
}

/**
 * clears the stack
 **/

void mystack::clear()
{
	stacksize = 0;
}

/**
 * reserves space for the stack array
 * @param z amount of space preserveed
 **/

void mystack::reserve(size_t z)
{
	if (z < stacksize || z == stackcap)
	{
		return;
	}
	char* RC = new char[z];
	stackcap = z;
	for (size_t i = 0; i < stacksize; i++)
	{
		RC[i] = sap[i];
	}
	delete[] sap;
	sap = RC;
}

/**
 * top element of stack
 * @returns reference to the top element
 **/

const char& mystack::top() const
{
	return sap[stacksize-1];
}

/**
 * push element to stack
 * @param y element to be pushed.
 **/

void mystack::push(char y)
{
	if (stacksize == stackcap)
	{
		if (stackcap == 0)
		{
			reserve(1);
		}
	    else
	    {
		    reserve(stackcap * 2);
	    }
    }
sap[stacksize] = y;
stacksize++;
}

/**
 * pops top element from stack.
 **/
 
void mystack::pop()	
{
	stacksize--;
}
