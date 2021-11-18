#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a = 0;
    bool b = false;
    auto C = {"qwe", "asd"};

    cout << "= " + to_string(b) << endl;

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