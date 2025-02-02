#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;


// Account number generator
int generateAccountNumber() {
    static int accountNumber = 100000;
    return accountNumber++;
}

// Definition of the BankAccount class

class BankAccount {
private:
    string name;
    double balance;
    int accountNumber;

public:
    //Default Constructor
    BankAccount() {
        name = "Unknown";
        balance = 0.0;
        accountNumber = generateAccountNumber();
    }

    // Parameterized Constructor
    BankAccount(string accName, double initialBalance) {
        name = accName;
        balance = initialBalance;
        accountNumber = generateAccountNumber();
    }

    int getAccountNumber() {
        return accountNumber;
    }

    double deposit(double amount) {
        balance += amount;
        cout << "You have deposited: $" << amount << endl;
        cout << "Your new balance is: $" << balance << endl;
        return balance;
    }

    double withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
            return -1;
        }
        if (amount < 0) {
            cout << "Invalid amount!" << endl;
            return -1;
        }
        balance -= amount;
        cout << "You have withdrawn: $" << amount << endl;
        return balance;
    }

    void displayBalance() {
        cout << "Dear " << name << ", Your balance is: $" << balance << endl;
    }
};

// Function prototype for bankMenu
void bankMenu(BankAccount &acc);

// Storage for bank accounts

unordered_map<int, BankAccount> accounts;

void createAccount() {
    string userName;
    double initialDeposit;

    cout << "Enter Your Name: ";
    cin.ignore(); //clear any new line left in the input buffer  
    getline(cin, userName);

    cout << "Enter initial deposit: ";
    cin >> initialDeposit;
    cin.ignore();
    
    // Create new account and store it
    BankAccount newAccount(userName, initialDeposit);
    int accNumber = newAccount.getAccountNumber();
    accounts[accNumber] = newAccount;

    cout << "New Account successfully created! Your account number is: " << accNumber << endl;
    
    bankMenu(accounts[accNumber]);

}

void accessAccount() {
    int accNum;
    cout << "Enter your account number: ";
    cin >> accNum;

    // Check if the account exists
    auto it = accounts.find(accNum);
    if (it == accounts.end()) {
        cout << "Account not found!" << endl;
        return;
    }

    BankAccount &acc = it->second; // Get the existing account
    bankMenu(acc); // Call bank menu
}


// Definition of the bankMenu function
void bankMenu(BankAccount &acc) {
    int choice;
    do {
        cout << "\n====== BANK MENU ======" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Display Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        
        cin >> choice;

        //check for invalid input so the program doesn't get into an infinite loop 
        if (cin.fail()) {
                        cin.clear();  // Reset error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
                        cout << "Invalid input! Please enter a number.\n";
                        continue; //restart the loop
}

        double amount;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                acc.deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                acc.withdraw(amount);
                break;
            case 3:
                acc.displayBalance();
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Enter 1 to 4." << endl;
        }
    } while (choice != 4);
}

int main() {
    int choice;
    do {
        cout << "\n====== WELCOME TO THE BANK ======" << endl;
        cout << "1. Create New Account" << endl;
        cout << "2. Access Existing Account" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                accessAccount();
                break;
            case 3:
                cout << "Thank you for banking with us!" << endl;
                break;
            default:
                cout << "Invalid choice! Enter 1 to 3." << endl;
        }
    } while (choice != 3);

    return 0;
}
