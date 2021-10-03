/*CSCI 241       Assignment 5   Spring 2021
Programmer: Christopher Huguelet
Section: 2
Date Due: 2/25/2021
Purpose: this program is created in order to simulate a simple computer called simplesim
*/
#include <iostream>

#include "bank.h"
#include "account.h"

using namespace std;

int main()
{
Bank Chase;
Chase.read_accounts("accounts");
Chase.print();
Chase.process_transactions("transactions.txt");
Chase.print();

return 0;
}
