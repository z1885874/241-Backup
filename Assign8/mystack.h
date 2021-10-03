/*CSCI 241       Assignment 7   Spring 2021
Programmer: Christopher Huguelet
Section: 2
Date Due: 3/12/2021
Purpose: this program is created in order to simulate a simple computer called simplesim
*/

#ifndef MYSTACK_H
#define MYSTACK_H
#include <cstddef>

struct node {
int value;
node* next;
node (int value = 0, node* next = nullptr)
{
this->value = value;
this->next = next;	
}
};

class mystack
{
	private:
    node* sap;
	size_t stacksize;
	void clone (const mystack&);  
	
	public:
	mystack();
	mystack(const mystack&);
	~mystack();
	mystack& operator= (const mystack&);
	size_t size() const;
	bool empty() const;
	void clear();
	const int& top() const;
	void push(int);
    void pop();	
};

#endif
