#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

struct Account {
    int accountNumber;
    string firstName;
    string middleName;
    string lastName;
    string birthdate;
    string age;
    double balance;
    int pin;
};

vector<Account> accounts;
int nextAccountNumber = 1234567;
int findAccount(int accNo) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].accountNumber == accNo)
            return i;
    }
    return -1;
}

void createAccount() {
    Account acc;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\n********* CREATE ACCOUNT ********\n";
    cout << "Enter First Name: ";
    getline(cin, acc.firstName);
    cout << "Enter Middle Name: ";
    getline(cin, acc.middleName);
    cout << "Enter Last Name: ";
    getline(cin, acc.lastName);
    cout << "Enter Birthdate (MM/DD/YY): ";
    getline(cin, acc.birthdate);
    cout << "Enter Age: ";
    getline(cin, acc.age);
    do {
        cout << "Enter 4-Digit PIN Code: ";
        cin >> acc.pin;
        if (acc.pin < 1000 || acc.pin > 9999) {
            cout << "Invalid PIN! PIN must be exactly 4 digits.\n";
        }
    } while (acc.pin < 1000 || acc.pin > 9999);
    acc.accountNumber = nextAccountNumber++;
    acc.balance = 0.0;
    accounts.push_back(acc);
    cout << "\n***********************************\n";
    cout << " ACCOUNT CREATED SUCCESSFULLY!\n";
    cout << "***************************************\n";
    cout << "Account Number: " << acc.accountNumber << endl;
    cout << "Balance: PHP 0.00\n";
}

int login() {
    int accNo, pin;
    cout << "\n------ LOGIN ------\n";
    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter your 4-Digit PIN: ";
    cin >> pin;
    int index = findAccount(accNo);
    if (index == -1) {
        cout << "Couldn’t find your Online Bank Account!\n";
        return -1;
    }
    if (accounts[index].pin != pin) {
        cout << "Incorrect PIN!\n";
        return -1;
    }
    cout << "\nLogin Successful!\n";
    cout << "Welcome, "
         << accounts[index].firstName << " "
         << accounts[index].lastName << "!\n";
    return index;
}

void deposit() {
    int accNo, pin;
    double amount;
    cout << "\n-------------------------\n";
    cout << "Deposit ng mga Niggers.\n";
    cout << "---------------------------\n";
    cout << "\nEnter Account Number: ";
    cin >> accNo;
    int index = findAccount(accNo);
    if (index == -1) {
        cout << "Couldn’t find your Online Bank Account!\n";
        return;
    }
    cout << "Enter PIN: ";
    cin >> pin;
    if (pin != accounts[index].pin) {
        cout << "Incorrect PIN!\n";
        return;
    }
    cout << "Enter Deposit Amount: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "Invalid Amount!\n";
        return;
    }
    accounts[index].balance += amount;
    cout << "\n===== RECEIPT =====\n";
    cout << "Account No: " << accNo << endl;
    cout << "Deposited: PHP "
         << fixed << setprecision(2)
         << amount << endl;
    cout << "New Balance: PHP "
         << accounts[index].balance << endl;
}

void withdrawMoney() {
    int accNo, pin;
    double amount;
     cout << "\n-------------------------\n";
    cout << "Withdraw ng mga Niggers.\n";
    cout << "---------------------------\n";
    cout << "\nEnter Account Number: ";
    cin >> accNo;
    int index = findAccount(accNo);
    if (index == -1) {
        cout << "Couldn’t find your Online Bank Account!\n";
        return;
    }
    cout << "Enter PIN: ";
    cin >> pin;
    if (pin != accounts[index].pin) {
        cout << "Incorrect PIN!\n";
        return;
    }
    cout << "Enter Withdrawal Amount: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "Invalid Amount!\n";
    }
    else if (amount > accounts[index].balance) {
        cout << "Insufficient Balance!\n";
    }
    else {
        accounts[index].balance -= amount;
        cout << "\n===== RECEIPT =====\n";
        cout << "Account No: " << accNo << endl;
        cout << "Withdrawn: PHP "
             << fixed << setprecision(2)
             << amount << endl;
        cout << "Remaining Balance: PHP "
             << accounts[index].balance << endl;
    }
}

void transferFunds() {
    int sender, receiver, pin;
    double amount;
     cout << "\n-------------------------\n";
    cout << "Transfer Funds.\n";
    cout << "---------------------------\n";
    cout << "\nEnter Sender Account Number: ";
    cin >> sender;
    cout << "Enter Receiver Account Number: ";
    cin >> receiver;
    int senderIndex = findAccount(sender);
    int receiverIndex = findAccount(receiver);
    if (senderIndex == -1 || receiverIndex == -1) {
        cout << "Invalid Account Number!\n";
        return;
    }
    cout << "Enter Sender PIN: ";
    cin >> pin;
    if (pin != accounts[senderIndex].pin) {
        cout << "Incorrect PIN!\n";
        return;
    }
    cout << "Enter Amount to Transfer: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "Invalid Amount!\n";
    }
    else if (amount > accounts[senderIndex].balance) {
        cout << "Insufficient Balance!\n";
    }
    else {
        accounts[senderIndex].balance -= amount;
        accounts[receiverIndex].balance += amount;
        cout << "\nTransfer Successful!\n";
        cout << "Transferred PHP "
             << fixed << setprecision(2)
             << amount << endl;
    }
}

void showBalance() {
    int accNo, pin;
    cout << "\nEnter Account Number: ";
    cin >> accNo;
    int index = findAccount(accNo);
    if (index == -1) {
        cout << "Couldn’t find your Online Bank Account!\n";
        return;
    }
    cout << "Enter PIN: ";
    cin >> pin;
    if (pin != accounts[index].pin) {
        cout << "Incorrect PIN!\n";
        return;
    }
    cout << "\n***** ACCOUNT DETAILS *****\n";
    cout << "Name: "
         << accounts[index].firstName << " "
         << accounts[index].middleName << " "
         << accounts[index].lastName << endl;
    cout << "Birthdate: "
         << accounts[index].birthdate << endl;
    cout << "Age: "
         << accounts[index].age << endl;
    cout << "Balance: PHP "
         << fixed << setprecision(2)
         << accounts[index].balance << endl;
}

int main() {
    int choice;
    do {
        cout << "\n***********************************\n";
        cout << "   WELCOME TO ONLINE BANKING\n";
        cout << "*************************************\n";
        cout << "1. Login\n";
        cout << "2. Create Account\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int userIndex = login();
            if (userIndex != -1) {
                int bankingChoice;
                do {
                    cout << "\n*******************************\n";
                    cout << "      ONLINE BANKING SYSTEM\n";
                    cout << "**********************************\n";
                    cout << "1. Deposit\n";
                    cout << "2. Withdraw\n";
                    cout << "3. Transfer Funds\n";
                    cout << "4. My Account/Balance\n";
                    cout << "5. Logout\n";
                    cout << "Enter Choice: ";
                    cin >> bankingChoice;
                    switch (bankingChoice) {
                    case 1:
                        deposit();
                        break;
                    case 2:
                        withdrawMoney();
                        break;
                    case 3:
                        transferFunds();
                        break;
                    case 4:
                        showBalance();
                        break;
                    case 5:
                        cout << "Logged Out Successfully!\n";
                        break;

                    default:
                        cout << "Invalid Choice... Please Try Again!!!\n";
                    }
                } while (bankingChoice != 5);
            }
            break;
        }
        case 2:
            createAccount();
            break;
        case 3:
            cout << "\nThank you for using Online Banking System.\n";
            break;

        default:
            cout << "Invalid Choice... Please Try Again.\n";
        }
    } while (choice != 3);

    return 0;
}
