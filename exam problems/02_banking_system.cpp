#include<iostream>
using namespace std;

class Account {
    protected:
    int accountNumber;
    string name;
    float balance;
    static int activeAccount;

    public:
    Account(int a, string n, float b):accountNumber(a),name(n),balance(b){
        activeAccount++;
    }

    void deposit(float d){
        balance=balance+d;
    }

    virtual void withdraw(float x){
        if(x>balance){
            throw "You cannot withdraw more money than your balance\n";
            return;
        }
        balance=balance-x;
    }

    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Balance: "<<balance<<endl;
    }

    static void displayAccount(){
        cout<<"Total no of Account is "<<activeAccount<<endl;
    }

    virtual ~Account(){
        activeAccount--;
    }
};

int Account::activeAccount=0;

class SavingsAccount:public Account{
    float interestRate;
    public:
    SavingsAccount(int a, string n, float b, float rate): Account(a,n,b){
        interestRate=rate;
    };
    float calculateInterest(){
        return balance*interestRate;
    }
};

class CurrentAccount:public Account{
    float minBalance;
    public:
    CurrentAccount(int a, string n, float b, float m):Account(a,n,b){
        minBalance=m;
    }
    void withdraw(float b) override{
        if((balance-b)<minBalance){
            throw "Minimum Balance Exceeding\n";
            return;
        }
        balance=balance-b;
    }
};

int main() {
    try {
        cout << "=== Creating valid SavingsAccount ===" << endl;
        SavingsAccount sa(101, "Riya", 1000, 0.05);
        sa.display();

        cout << "\n=== Applying interest and depositing ===" << endl;
        sa.calculateInterest();  // Adds interest
        sa.deposit(500);     // Valid deposit
        sa.display();

        cout << "\n=== Trying to deposit negative amount ===" << endl;
        sa.deposit(-100);    // ❌ Should throw

    } catch (const char* msg) {
        cout << "Exception: " << msg;
    }

    try {
        cout << "\n=== Trying to withdraw more than balance in SavingsAccount ===" << endl;
        SavingsAccount sa2(102, "Tina", 300, 0.04);
        sa2.withdraw(1000);  // ❌ Should throw
    } catch (const char* msg) {
        cout << "Exception: " << msg;
    }

    try {
        cout << "\n=== Creating CurrentAccount and valid withdrawal ===" << endl;
        CurrentAccount ca(201, "Rohan", 2000, 500);
        ca.withdraw(1300);  // ✅ Valid, leaves 700
        ca.display();

        cout << "\n=== Trying to withdraw violating minimum balance ===" << endl;
        ca.withdraw(300);   // ❌ Leaves only 400, minBalance is 500 → Should throw

    } catch (const char* msg) {
        cout << "Exception: " << msg;
    }

    try {
        cout << "\n=== Creating account with negative initial balance ===" << endl;
        SavingsAccount sa3(301, "Invalid", -500, 0.03); // ❌ Should throw
    } catch (const char* msg) {
        cout << "Exception: " << msg;
    }

    cout << "\n=== Displaying Active Account Count ===" << endl;
    Account::displayAccount(); // Will show correct number of live accounts

    return 0;
}
