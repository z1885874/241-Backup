/*CSCI 241       Assignment 7   Spring 2021
Programmer: Christopher Huguelet
Section: 2
Date Due: 3/12/2021
Purpose: this program is created in order to simulate a simple computer called simplesim
*/

#ifndef MYSTACK_H
#define MYSTACK_H
#include <cstddef>

class mystack
{
	private:
    char* sap;
	size_t stackcap;
	size_t stacksize;
	
	public:
	mystack();
	mystack(const mystack&);
	~mystack();
	mystack& operator= (const mystack&);
	size_t capacity() const;
	size_t size() const;
	bool empty() const;
	void clear();
	void reserve(size_t);
	const char& top() const;
	void push(char);
    void pop();	
};

#endif
