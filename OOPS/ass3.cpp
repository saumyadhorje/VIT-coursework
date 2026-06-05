#include <iostream>
using namespace std;

class bankAcc {

private:
    int balance;

    static int totalAccounts;
    static int totalBalance;

public:

    // constructor
    bankAcc(int b) {
        balance = b;

        totalAccounts++;
        totalBalance = totalBalance + balance;
    }

    // static function
    static void show() {
        cout << "Total Accounts: " << totalAccounts << endl;
        cout << "Total Balance: " << totalBalance << endl;
    }

    // compare balances
    void compare(bankAcc x) {

        if(balance < x.balance)
            cout << balance << " " << x.balance << endl;

        else
            cout << x.balance << " " << balance << endl;
    }
};

// static variable definition
int bankAcc::totalAccounts = 0;
int bankAcc::totalBalance = 0;

int main() {

    bankAcc b1(5000);
    bankAcc b2(3000);

    bankAcc::show();

    cout << "Balances in ascending order: ";
    b1.compare(b2);

    return 0;
}