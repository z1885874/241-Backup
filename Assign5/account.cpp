#include "account.h"

using namespace std;

/**
 * default constructor
 * Sets account name and number to "None" and Balance to zero
 **/
account::account()
{
	strcpy(accNum, "None");
	strcpy(accName, "None");
	accBal = 0;
}

/**
 * account number obtainer
 * 
 * @return the account number
 **/
 const char* account::getAccNum() const
 {
 return accNum;
 }
 
 /**
  * Account balance obtainer
  * 
  * @return Current account balance
  **/
  const double account::getBal() const
  {
      return accBal;
  }
  
  /**
   * processes deposit requests
   * 
   * @param amount Amount to be deposeted into the afformentioned account
   **/
  void account::processDepo(double amount)
  {
  accBal += amount;
  }
  
  /**
   * process a withdrawl request
   * 
   * @param amount Amount to be withdrawn
   * 
   * @return will be true if the withdrawl is successful, false if not enough money
   **/
   const bool account::processWith(const double amount)
   {
   if(amount>accBal) return false;
   accBal -=amount;
   return true;
   }
   
   /**
    * prints a summery of the account
    **/
    void account::print() const
    {
		cout << "Account Number: " << accNum << endl;
		cout << "Name: " << accName << endl;
		cout << "Balance: $" << fixed << setprecision(2) << accBal << endl << endl;
	}

