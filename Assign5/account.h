#include <iostream>
#include <iomanip>
#include <cstring>

#ifndef ACCOUNT_H
#define ACCOUNT_H

class account
{
private:
    char accNum[11] = {};
    char accName[21] = {};
    double accBal = 0;
    
public:
    account();
    const char* getAccNum() const;
    const double getBal() const;
    void processDepo(double);
    const bool processWith(const double);
    void print() const;
};

#endif
