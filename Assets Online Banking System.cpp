#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Account {
    int accountNumber;
    string name;
    double balance;
};

vector<Account> accounts;
int nextAccountNumber = 1001;

void createAccount() {
    Account acc;

    cout << "\nEnter Account Holder Name: ";
    cin.ignore();
    getline(cin, acc.name);

    acc.accountNumber = nextAccountNumber++;
    acc.balance = 0.0;

    accounts.push_back(acc);

    cout << "\nAccount Created Successfully!\n";
    cout << "Account Number: " << acc.accountNumber << endl;
}

int findAccount(int accNo) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].accountNumber == accNo)
            return i;
    }
    return -1;
}

void deposit() {
    int accNo;
    double amount;

    cout << "\nEnter Account Number: ";
    cin >> accNo;

    int index = findAccount(accNo);

    if (index == -1) {
        cout << "Account not found!\n";
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
    cout << "Deposited: PHP " << fixed << setprecision(2) << amount << endl;
    cout << "New Balance: PHP " << accounts[index].balance << endl;
}

void withdrawMoney() {
    int accNo;
    double amount;

    cout << "\nEnter Account Number: ";
    cin >> accNo;

    int index = findAccount(accNo);

    if (index == -1) {
        cout << "Account not found!\n";
        return;
    }

    cout << "Enter Withdrawal Amount: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid Amount!\n";
        return;
    }

    if (amount > accounts[index].balance) {
        cout << "Insufficient Balance!\n";
        return;
    }

    accounts[index].balance -= amount;

    cout << "\n===== RECEIPT =====\n";
    cout << "Account No: " << accNo << endl;
    cout << "Withdrawn: PHP " << fixed << setprecision(2) << amount << endl;
    cout << "Remaining Balance: PHP " << accounts[index].balance << endl;
}

void transferFunds() {
    int sender, receiver;
    double amount;

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

    cout << "Enter Amount to Transfer: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid Amount!\n";
        return;
    }

    if (amount > accounts[senderIndex].balance) {
        cout << "Insufficient Balance!\n";
        return;
    }

    accounts[senderIndex].balance -= amount;
    accounts[receiverIndex].balance += amount;

    cout << "Transfer Successful!\n";
}

void showBalance() {
    int accNo;

    cout << "\nEnter Account Number: ";
    cin >> accNo;

    int index = findAccount(accNo);

    if (index == -1) {
        cout << "Account not found!\n";
        return;
    }

    cout << "\nAccount Name: " << accounts[index].name << endl;
    cout << "Balance: PHP "
         << fixed << setprecision(2)
         << accounts[index].balance << endl;
}

int main() {
    int choice;

    do {
        cout << "\n=============================\n";
        cout << " ONLINE BANKING SYSTEM\n";
        cout << "=============================\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer Funds\n";
        cout << "5. Show Balance\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                transferFunds();
                break;
            case 5:
                showBalance();
                break;
            case 6:
                cout << "Thank you for using the system.\n";
                break;
            default:
                cout << "Invalid Choice!... Please Try Again!!!";
        }

    } while(choice != 6);

    return 0;
}
