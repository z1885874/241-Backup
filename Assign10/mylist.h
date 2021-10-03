#ifndef MYLIST_H
#define MYLIST_H
#include <cstdlib>
#include <iostream>
#include <stdexcept>

template<class T>
struct node
{
    T value; 
    node<T>* previous;
    node<T>* next;
    node<T> (T value= T(), node<T>* previous = nullptr, node<T>* next = nullptr):
    value(value), previous(previous), next(next){}
};

template<class T> class mylist;
template<class T> std::ostream& operator<< (std::ostream&, const mylist<T>&);

template<class T>
class mylist
{
    private:
    node<T>* L_front;
    node<T>* L_back;
    size_t L_size;
    void clone(const mylist&);

    public: 
    mylist();
    ~mylist();
    mylist(const mylist&);
    mylist& operator=(const mylist&);

    void clear();
    size_t size () const;
    bool empty() const;

    const T& front() const;
    T& front();
    void push_front(const T&);
    void pop_front();

    const T& back() const;
    T& back();
    void push_back(const T&);
    void pop_back();

    bool operator==(const mylist&) const;
    bool operator<(const mylist&) const;
    friend std::ostream& operator<< <> (std::ostream&, const mylist&);

};

/**
* default constructor
**/
template<class T>
mylist<T>::mylist()
{
    L_front = nullptr;
    L_back = nullptr;
    L_size = 0;
} 

/**
* deconstructor
**/
template<class T>
mylist<T>::~mylist()
{
    clear();
}

/**
* copy constructor
@param list Source mylist
**/
template<class T>
mylist<T>::mylist(const mylist<T>& list)
{
    L_front = nullptr;
    L_back = nullptr;
    L_size = 0;
    clone(list);
}

/**
* copy assignment
**/
template<class T>
mylist<T>& mylist<T>::operator=(const mylist<T>& list)
{
    if(&list != this)
    {
        clear();
        clone(list);
    }
    return *this;
}

/**
* clear the list
**/
template<class T>
void mylist<T>::clear()
{
    while (!empty())
    {
        pop_front();
    }
}

/**
Size getter
**/
template<class T>
size_t mylist<T>::size() const
{
    return L_size;
}

/**
empty flag
**/
template<class T>
bool mylist<T>::empty() const
{
    return L_size == 0;
}

/**
front node getter
**/
template<class T>
const T& mylist<T>::front() const
{
    if(L_front == nullptr)
    {
        throw std::underflow_error("underflow exception on call to front()");
    
    }
    return L_front->value;
}

/**
front node changer
**/
template<class T>
T& mylist<T>::front()
{
    if(L_front == nullptr)
    {
        throw std::underflow_error("underflow exception on call to front()");
    
    }
    return L_front->value;
}

/**
push front
@param value = value being pushed
**/
template<class T>
void mylist<T>::push_front(const T& value)
{
    node<T>* n = new node <T>(value, nullptr, L_front);
    L_front = n;
    if (L_back == nullptr)
    {
        L_back = n;
    }
    else
    {
    L_front->next->previous = L_front;
    }
    L_size++;
}

/**
pop front
**/
template<class T>
void mylist<T>::pop_front()
{
    if(empty())
    {
        throw std::underflow_error("underflow exception on call to pop_front()");
    }
    node <T>* n = L_front;
    L_front = L_front->next;
    delete n;
    L_size--;
    if(empty())
    {
        L_back = nullptr;
    }
     
    else {L_front->previous = nullptr;}
}



/**
back node getter
**/
template<class T>
const T& mylist<T>::back() const
{
    if(L_back == nullptr)
    {
        throw std::underflow_error("underflow exception on call to back()");
    
    }
    return L_back->value;
}

/**
back node changer
**/
template<class T>
T& mylist<T>::back()
{
    if(L_back == nullptr)
    {
        throw std::underflow_error("underflow exception on call to back()");
    
    }
    return L_back->value;
}

/**
push back
@param value = value being pushed
**/
template<class T>
void mylist<T>::push_back(const T& value)
{
    node<T>* n = new node <T>(value, L_back, nullptr);
    L_back = n;
    if (L_front == nullptr)
    {
        L_front = n;
    }
    else
    {
    L_back->previous->next = L_back;
    }
    L_size++;
}

/**
pop back
**/
template<class T>
void mylist<T>::pop_back()
{
    if(empty())
    {
        throw std::underflow_error("underflow exception on call to pop_back()");
    }
    node <T>* n = L_back;
    L_back = L_back->previous;
    delete n;
    L_size--;
    if(empty())
    {
        L_front = nullptr;
    }
    else {L_back->next = nullptr;}
}

/**
* overloaded == operator
@param rhs = right hand side
**/
template<class T>
bool mylist<T>::operator==(const mylist<T>& rhs) const
{
    if (this->L_size != rhs.L_size)
    {
         return false;
    }
    bool equal = true;
    node<T>* left= L_front;
    node<T>* right = rhs.L_front;
    while (equal && left != nullptr)
    {
        equal = left->value == right->value;
        left = left->next;
        right = right->next;
    }
    return equal;
}

/**
overloaded < operator
@param rhs = right hand side
**/
template<class T>
bool mylist<T>::operator<(const mylist<T>& rhs) const
{
    node<T>* left= L_front;
    node<T>* right = rhs.L_front;
    while (left != nullptr && right != nullptr)
    {
        if (left->value != right->value)
        {
            return left->value<right->value;
        }
        left = left->next;
        right = right->next;
    }
    return this->L_size<rhs.L_size;
}

/**
stream insertion
@param os = output stream
@param list = list
**/
template<class T>
std::ostream& operator<<(std::ostream& os, const mylist<T>& list)
{
    node<T>* p = list.L_front;
    while(p != nullptr)
    {
        os << p->value << " ";
        p = p->next;
    }
    return os;
}

/**
*
**/
template<class T>
void mylist<T>::clone(const mylist<T> & list)
{
    node<T>* n = list.L_front;
    while (n != nullptr)
    {
        push_back(n->value);
        n = n->next;
    }
}

#endif