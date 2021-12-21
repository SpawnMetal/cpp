#include <iostream>
#include <string>
#include <typeinfo>
#include <tuple>
#include <algorithm>
#include <vector>
#include <functional>

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

tuple<int, string, double> f()
{
    int i{108};
    string s{"Some text"};
    double d{.01};
    return {i, s, d};
}

class Point
{
public:
    // Define "accessor" functions as
    //  reference types.
    unsigned &x();
    unsigned &y();

private:
    // Note that these are declared at class scope:
    unsigned obj_x;
    unsigned obj_y;
};

unsigned &Point ::x()
{
    return obj_x;
}
unsigned &Point ::y()
{
    return obj_y;
}

void MyFunc(int c)
{
    if (c > numeric_limits<char>::max())
        throw string("qwe");
    // throw invalid_argument("MyFunc argument too large.");
}

int main()
{
    // int a = 0;
    // bool b = false;
    // auto C = {"qwe", "asd"};
    // int nums[] = {5, 6, 8};
    // decltype(b) qwe = true;
    // cout << "= " + to_string(ex) << endl;

    /*
    try
    {
        MyFunc(256); //cause an exception to throw
    }

    catch (string &e)
    {
        cerr << e << endl;
        return -1;
    }
    // catch (invalid_argument &e)
    // {
    //     cerr << e.what() << endl;
    //     return -1;
    // }
    */

    /*
    Point ThePoint;
    // Use x() and y() as l-values.
    ThePoint.x() = 7;
    ThePoint.y() = 9;

    // Use x() and y() as r-values.
    cout << "x = " << ThePoint.x() << "\n"
         << "y = " << ThePoint.y() << "\n";
    */

    /*
    const int n = 5;
    int num[n]{5, 6};
    int qwe[] = {1, 2};
    for (int i = 0; i < n; i++)
        printf_s("%d\n", num[i]);
    printf_s("sizeof = %d\n", sizeof num);
    cout << typeid(qwe).name();
    */

    /*
    // Create a vector object that contains 9 elements.
    vector<int> v;
    for (int i = 1; i < 10; ++i)
    {
        v.push_back(i);
    }

    // Count the number of even numbers in the vector by
    // using the for_each function and a lambda.
    int evenCount = 0;
    for_each(v.begin(), v.end(), [&evenCount](int n)
             {
                 cout << n;
                 if (n % 2 == 0)
                 {
                     cout << " is even " << endl;
                     ++evenCount;
                 }
                 else
                 {
                     cout << " is odd " << endl;
                 }
             });

    // Print the count of even numbers to the console.
    cout << "There are " << evenCount
         << " even numbers in the vector." << endl;

    // Assign the lambda expression that adds two numbers to an auto variable.
    auto f1 = [](int x, int y)
    { return x + y; };

    cout << f1(2, 3) << endl;

    // Assign the same lambda expression to a function object.
    function<int(int, int)> f2 = [](int x, int y)
    { return x + y; };

    cout << f2(3, 4) << endl;
    */

    /*
    union Printable_t
    {
        int i;
        int j;
        float f;
        char c;
        char *s;
    } Printable;

    Printable.i = 5;
    Printable.j = 2;
    printf_s("i = %i\n", Printable.i);
    printf_s("j = %i\n", Printable.j);
    printf_s("i = %i\n", Printable.i);
    */

    /*
    auto t = f();
    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl; // 108 Some text 0.01
    // --or--
    int myval;
    string myname;
    double mydecimal;
    tie(myval, myname, mydecimal) = f();
    cout << myval << " " << myname << " " << mydecimal << endl; // 108 Some text 0.01
    */

    /*
    int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int y : x)
    {   // Access by value using a copy declared as a specific type.
        // Not preferred.
        cout << y << " ";
    }
    */

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