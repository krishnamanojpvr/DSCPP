/*
Write a C++ program to implement a class called BankAccount 
that has private member variables for account number and balance. 
Include member functions to deposit and withdraw money from the account 
using constructors.

Sample Output:

A/c. No.SB-123                                                                                                          
Balance: 1000                                                                                                          
Deposit Amount: 1500                                                                                                    
Deposit successful. Current balance: 2500                                                                               
Withdrawl Amount: 750                                                                                                   
Withdrawal successful. Current balance: 1750                                                                            
Attempt to withdrawl Amount: 1800                                                                                       
Insufficient balance. Cannot withdraw.                                                                                  
                                                                                                                        
                                                                                                    
                                                                                                                                     
                                                                                                                        
                                         
*/

#include<iostream>
#include<string>
using namespace std;

class bank{
    private:
        string accNo="SB-123";
        int balance = 1000;
    public:
        bank(){
            cout << "A/c. No."<<accNo << endl;
            cout << "Balance: " << balance << endl;
        }
        void deposit(){
            int depositAmount = 1500;
            cout << "Deposit Amount:"<<depositAmount<<endl;
            balance += depositAmount;
            cout << "Deposit successful. Current balance: " << balance << endl;
        }
        void withdraw(){
            int withdrawAmount = 750;
            cout << "Withdrawl Amount:"<<withdrawAmount<<endl;
            if(withdrawAmount > balance){
                cout << "Insufficient balance. Cannot withdraw." << endl;
            }
            else{
                balance -= withdrawAmount;
                cout << "Withdrawal successful. Current balance: " << balance << endl;
            }
        }
        void attempt(){
            int withdrawAmount =1800;
            cout << "Attempt to withdrawl Amount:"<<withdrawAmount<<endl;
            if(withdrawAmount > balance){
                cout << "Insufficient balance. Cannot withdraw." << endl;
            }
            else{
                balance -= withdrawAmount;
                cout << "Withdrawal successful. Current balance: " << balance << endl;
            }
            
            }    
};


int main(){
    bank b;
    b.deposit();
    b.withdraw();
    b.attempt();
    return 0;
}