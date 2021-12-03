#include <iostream>
#include <string>
#include <typeinfo>

#include "examples2.cpp"

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

size_t getPtrSize(char *ptr)
{
    return sizeof(ptr);
}

void showstat(int curr)
{
    static int nStatic; // Value of nStatic is retained
                        // between each function call
    nStatic += curr;
    cout << "nStatic is " << nStatic << endl;

    // nStatic is 0
    // nStatic is 1
    // nStatic is 3
    // nStatic is 6
    // nStatic is 10
}

struct Date
{
    Date(int i, int j, int k) : day(i), month(j), year(k) {}
    int month;
    int day;
    int year;
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

    /*
    Date mydate(1, 1, 1900);
    mydate.month = 2;
    cout << mydate.month << "/" << mydate.day
         << "/" << mydate.year << endl; // 2/1/1900

    Date *mydate2 = new Date(1, 1, 2000);
    mydate2->month = 2;
    cout << mydate2->month << "/" << mydate2->day
         << "/" << mydate2->year << endl;
    delete mydate2; // 2/1/2000
    */

    /*
    int a = 6;
    int *p = &a;
    cout << *p << endl;
    cout << p << endl;
    */

    /*
    // Необработанные строковые литералы, содержащие неэкранированные символы \ и "
    auto R0 = R"("Hello \ world")"; // const char*
    cout << R0 << endl;

    char newline = '\n';
    char tab = '\t';
    char backspace = '\b';
    char backslash = '\\';
    char nullChar = '\0';

    cout << "Newline character: " << newline << "ending" << endl;
    cout << "Tab character: " << tab << "ending" << endl;
    cout << "Backspace character: " << backspace << "ending" << endl;
    cout << "Backslash character: " << backslash << "ending" << endl;
    cout << "Null character: " << nullChar << "ending" << endl;
    */

    /*
    for (int i = 0; i < 5; i++)
        showstat(i);
    */

    /*
    char szHello[] = "Hello, world!";

    cout << "The size of a char is: "
         << sizeof(char)
         << "\nThe length of " << szHello << " is: "
         << sizeof szHello
         << "\nThe size of the pointer is "
         << getPtrSize(szHello) << endl;

    // The size of a char is: 1
    // The length of Hello, world! is: 14
    // The size of the pointer is 4
     */

    /*
    // Create objects of type CheckingAccount and SavingsAccount.
    CheckingAccount checking(100.00);
    SavingsAccount savings(1000.00);

    // Call PrintBalance using a pointer to Account.
    Account *pAccount = &checking;
    pAccount->PrintBalance();

    // Call PrintBalance using a pointer to Account.
    pAccount = &savings;
    pAccount->PrintBalance();
    */

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
    char asd[] = "\nasd";
    const char *s1 = "\npoint";

    cout << "qwe\n" + str +
                asd +
                s1 +
                "\nzxc\
                Continue";
    */

    return 0;
}