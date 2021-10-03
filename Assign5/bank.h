#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

#include "account.h"

#ifndef BANK_H
#define BANK_H

class Bank
{
    private:
        char bank_name[31] = {};
        account accounts[20] = {};
        int number_accounts = 0;
    
    public:
        Bank();
        void read_accounts(const char*);
        void process_transactions(const char*);
        void print() const;
    private:
        void sort_accounts();
        const int search_accounts(const char*) const;
        
};

#endif
