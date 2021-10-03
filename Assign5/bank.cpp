#include "bank.h"

using namespace std;

/**
 * default constructor
 * sets account number to zero, all acccounts to default value, and bank name to none
 **/
 Bank::Bank()
 {
	 strcpy(bank_name, "None");
	 number_accounts = 0;
 }
 
 /** 
  * reads bank name and account from the file
  * 
  * @param file_name File contining bank and account information
  * 
  * @note If the file fails to open, exits program with code -1
  **/
  void Bank::read_accounts(const char* file_name)
  {
	  ifstream file;
	  file.open(file_name);
	  
	  if(!file)
	  {
		  cout << "Error: Could not open file: " << file_name << endl;
		  exit(-1);
	  }
	  
	  file.read((char*) this,sizeof(Bank));
	  
	  file.close();
	  
	  sort_accounts();
  }
  
  /**
   * prints report with summeries of every account
   **/
   void Bank::print() const
   {
	   cout << "account listing for " << bank_name << endl << endl;
	   for(int i=0; i < number_accounts; i++)
	   {
		   accounts[i].print();
	   }
   }
   
   /**
    * processes transaction stored in file and prints out the transaction report
    * 
    * @param file_name File containing transaction records
    * 
    * @note If file fails to open, exits program with code -2
    **/
    void Bank::process_transactions(const char* file_name)
    {
	    cout << "Transaction Report\n\nDate    account      Type   Amount     New Balance" << endl << endl;
	    
	    ifstream file;
	    file.open(file_name);
	    if(!file)
	    {
			cout << "ERROR: Could not open file: " << file_name << endl;
			exit(-2);
		}
    char date[6] = {};
    char account_number[11] ={};
    char type = 0;
    double amount = 0;
    
    file >> date;
    file >> account_number;
    file >> type;
    file >> amount;
    
    while(file)
    {
		cout << left << setw(8) << date << setw(13) << account_number << setw(1) << type << right << fixed << setprecision(2) << setw(14) << amount << "    " << endl;
		int accIndex = search_accounts(account_number);
		
		if(accIndex == -1)
		{
			cout <<"*** Invalid account number ***" << endl;
		}
		else
		{
			if(type == 'D')
			{
				accounts[accIndex].processDepo(amount);
				cout << right << fixed << setprecision(2) << setw(8) << accounts[accIndex].getBal() << endl;
			} 
		    else
		    {
				if(accounts[accIndex].processWith(amount))
				{
					cout << right << fixed << setprecision(2) << setw(8) << accounts[accIndex].getBal() << endl;
				}
				else
				{
					cout << "*** Insufficient funds ***" << endl;
				}
			}
		}
		file >> date;
		file >> account_number;
		file >> type;
		file >> amount;
    
	}
  }
		
    
    /**
     * sorts accounts into ascending order based upon account number
     **/
     void Bank::sort_accounts()
     {
		 for(int i = 1; i < number_accounts; i++)
		     for(int j=0; j < number_accounts - i; j++)
		         if(strcmp(accounts[j].getAccNum(),accounts[j+1].getAccNum())>0)
		             swap(accounts[j],accounts[j+1]);
     }
     
     /**
      * searches list of accounts for the specified account number
      * 
      * @param account_number the account number to search for
      * 
      * @return Index of the account in the account lists, -1 if no account found
      **/
      const int Bank::search_accounts(const char* account_number) const
      {
		  for(int i = 0; i < number_accounts; i++)
		  {
			  if(strcmp(account_number, accounts[i].getAccNum())==0)
			  {
				  return i;
			  }
		  }
		  return -1;
	  }
	  
	  
		
