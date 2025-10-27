#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Global variables
string pin = "1234";          // Predefined PIN
double balance = 1000.0;      // Initial balance
vector<string> history;       // Transaction history

// Function to display menu
void displayMenu() {
    cout << "\nATM Menu:\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. View Transaction History\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Function to check balance
void checkBalance() {
    cout << "Your balance is: ₹" << balance << endl;
}

// Function to deposit money
void depositMoney() {
    double amount;
    cout << "Enter amount to deposit: ₹";
    cin >> amount;
    if(amount > 0) {
        balance += amount;
        cout << "Amount deposited successfully!\n";
        history.push_back("Deposited: ₹" + to_string(amount));
    } else {
        cout << "Invalid amount!\n";
    }
}

// Function to withdraw money
void withdrawMoney() {
    double amount;
    cout << "Enter amount to withdraw: ₹";
    cin >> amount;
    if(amount > balance) {
        cout << "Insufficient balance!\n";
    } else if(amount <= 0) {
        cout << "Invalid amount!\n";
    } else {
        balance -= amount;
        cout << "Please collect your cash.\n";
        history.push_back("Withdrawn: ₹" + to_string(amount));
    }
}

// Function to display transaction history
void showHistory() {
    if(history.empty()) {
        cout << "No transactions yet.\n";
    } else {
        cout << "Transaction History:\n";
        for(string record : history) {
            cout << record << endl;
        }
    }
}

int main() {
    string enteredPin;
    int attempts = 0;

    cout << "Welcome to Advanced ATM Simulation!\n";

    // PIN Verification (3 attempts)
    while(attempts < 3) {
        cout << "Enter your 4-digit PIN: ";
        cin >> enteredPin;
        if(enteredPin == pin) {
            break;
        } else {
            attempts++;
            cout << "Incorrect PIN! Attempts left: " << 3 - attempts << endl;
        }
    }

    if(attempts == 3) {
        cout << "Too many incorrect attempts! Exiting...\n";
        return 0;
    }

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch(choice) {
            case 1: checkBalance(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: showHistory(); break;
            case 5: cout << "Thank you for using our ATM. Goodbye!\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 5);

    return 0;
}
