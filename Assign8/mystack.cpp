#include "mystack.h"

/**
 * default contructor
 **/
mystack::mystack()
{
	sap = nullptr;
	stacksize = 0;
}

/**
 * copy constructor
 **/

mystack::mystack(const mystack& x)
{
	stacksize = x.stacksize;
	clone(x);
}

/**
 * destructor
 **/

mystack::~mystack()
{
	clear();
}

/**
 * copy assignment
 **/

mystack& mystack::operator= (const mystack& x)
{
	if (&x != this)
	{
		clear();
	    stacksize = x.stacksize;
	    clone(x);
}
return *this; }


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
	while (not empty())
	{
		pop();
	}
}

/**
 * top element of stack
 * @returns reference to the top element
 **/

const int& mystack::top() const
{
	return sap->value;
}

/**
 * push element to stack
 * @param y element to be pushed.
 **/

void mystack::push(int i)
{
	node* n = new node(i, sap);
	stacksize++;
	sap = n;
}

/**
 * pops top element from stack.
 **/
 
void mystack::pop()	
{
	stacksize--;
	node* n = sap;
	sap = n->next;
	delete n;
}

/**
 * deep copy linked list from source to this.
 * @param x The source stack
 **/

void mystack::clone(const mystack& x)
{
    node* last = nullptr;
    node* ptr = x.sap;
    while (ptr)
    {
	node* n = new node(ptr->value);
	if (last == nullptr)
	{
		sap = n;
	}
	else
	{
		last->next = n;
	}
	last = n;
	ptr = ptr->next;
	}
} 
