#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class BankAccount{

    private:
        string name; 
        double balance;

        public:
        BankAccount(string accName, double initialBalance){
            name = accName;
            balance = initialBalance;
        }

//returns the new balance
        double deposit(double amount){
            balance += amount;
            cout << "You have deposited: $" << amount << endl ;
            cout << "Your new balance is: $" << balance << endl;
            return balance;
        }

        double withdraw(double amount){
            if (amount > balance){
                cout << "You have insufficient funds to make the withdrawal" << endl;
                return -1; //not enough money
            }
            else if(amount < 0){
                cout << "You cannot withdraw a negative amount" << endl;
                return -1; //negative amount
                }
                else{
                    balance -=amount;
                    cout << "You have withdrawn: $" << amount <<  endl;
                    return balance;
                }
        }
        //function to display the balance
        double displayBalance(){
            cout << "Dear" << name << "Your balance is: $" << balance << endl;
        }

        

};

//function to handle the bank menu and other choices 

void bankMenu(BankAccount &acc1){
    int choice;
    do{
        cout << "======BANK MENU======" << endl;
        cout << "Enter your choice: " << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Display Balance" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;

        double amount;
         
            switch (choice){
                case 1:
                cout << "How much would you like to deposit?" << endl;  
                cin  >> amount;
                acc1.deposit(amount);
                break;
                case 2:
                cout << "How much would you like to withdraw?" << endl;
                cin >> amount;
                acc1.withdraw(amount);
                break;
                case 3:
                acc1.displayBalance();
                break;
                case 4:
                cout << "Goodbye!" << endl;
                break;
                deffault:
                cout << "Invalid choice, enter a value from 1 to 4" << endl;
            }
    }while (choice !=4); 

}


int main() {
  string userName;
  double initialDeposit;
  //ask for the name and starting deposit
  cout << "Welcome to our bank! This is your investment of choice." << endl;
  cout << "Please enter your name: ";
  getline(cin,userName);
  cout << "Please enter your initial deposit: ";
  cin >> initialDeposit;    

  //create a bank account for the user 
  BankAccount acc1(userName, initialDeposit);

  //call the bankMenu function
  bankMenu(acc1);
    return 0;
}