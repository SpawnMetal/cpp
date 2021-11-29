#include <iostream>
#include <string>
#include "examples2.cpp"
#include <typeinfo>

using namespace std;

class CCTest
{
public:
    void setNumber(int);
    void printNumber() const;

private:
    int number;
};

void CCTest::setNumber(int num) { number = num; }

void CCTest::printNumber() const
{
    cout << "\nBefore: " << number; // 8
    const_cast<CCTest *>(this)->number--;
    cout << "\nAfter: " << number; // 7
}

//

class Account
{
public:
    Account(double d) { _balance = d; }
    virtual ~Account() {}
    virtual double GetBalance() { return _balance; }
    virtual void PrintBalance() { cerr << "Error. Balance not available for base type." << endl; } // Сработает, если закомментить virtual

private:
    double _balance;
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(double d) : Account(d) {}
    void PrintBalance() { cout << "Checking account balance: " << GetBalance() << endl; }
};

class SavingsAccount : public Account
{
public:
    SavingsAccount(double d) : Account(d) {}
    void PrintBalance() { cout << "Savings account balance: " << GetBalance(); }
};

int main()
{
    // int a = 0;
    // bool b = false;
    // auto C = {"qwe", "asd"};
    // int nums[] = {5, 6, 8};
    // decltype(b) qwe = true;

    // printf_s("%d\n", b);
    // cout << "= " + to_string(ex) << endl;

    // Create objects of type CheckingAccount and SavingsAccount.
    CheckingAccount checking(100.00);
    SavingsAccount savings(1000.00);

    // Call PrintBalance using a pointer to Account.
    Account *pAccount = &checking;
    pAccount->PrintBalance();

    // Call PrintBalance using a pointer to Account.
    pAccount = &savings;
    pAccount->PrintBalance();

    /*
    int i = 0; // hidden by var with same name declared in for loop
    for (int i = 0; i < 3; i++)
    {
        printf_s("%d\n", i);
    }
    i++;
    printf_s("i=%d\n", i);
    for (int i = 0; i < 3; i++)
    {
        printf_s("%d\n", i);
    }
    printf_s("i=%d\n", i);
    */

    /*
    CCTest X;
    X.setNumber(8);
    X.printNumber();
    */

    /*
    unsigned short y = 0xFFEE;
    cout << hex << y << endl;
    y = ~y; // Take one's complement
    cout << hex << y << endl;
    */

    /*
    unsigned short a = 0x5555; // pattern 0101 ...
    unsigned short b = 0xAAAA; // pattern 1010 ...

    cout << hex << (a | b) << endl; // prints "ffff" pattern 1111 ...
    */

    /*
    unsigned short a = 0xFFFF; // pattern 1111 ...
    unsigned short b = 0xAAAA; // pattern 1010 ...

    cout << hex << (a & b) << endl; // prints "aaaa", pattern 1010 ...
    */

    /*
    int count = 10;
    int &countRef = count;
    auto myAuto = countRef;

    countRef = 11;
    cout << count << " ";

    myAuto = 12;
    cout << count << endl; // 11 11. Если myAuto объявить &myAuto тогда будет 11 12
    */

    /*
    int a = 3, b = 6, c = 10, d = 0xAAAA, e = 0x5555;

    a += b;  // a is 9
    b %= a;  // b is 6
    c >>= 1; // c is 5
    d |= e;  // Bitwise--d is 0xFFFF

    cout << "a = 3, b = 6, c = 10, d = 0xAAAA, e = 0x5555" << endl
         << "a += b yields " << a << endl
         << "b %= a yields " << b << endl
         << "c >>= 1 yields " << c << endl
         << "d |= e yields " << hex << d << endl;
    */

    /*
    string str = "str";

    cout << "qwe\n" + str +
                "\nasd"
                "\nzxc";
    */

    return 0;
}