#include <iostream>

using namespace std;

int main()
{
    int val = 9;
    int *ptrval = &val;
    int &ptr = val;

    cout << "val = " << val << endl;         // val = 9
    cout << "&val = " << &val << endl;       // &val = 0x61fe0c
    cout << "ptrval = " << ptrval << endl;   // ptrval = 0x61fe0c
    cout << "*ptrval = " << *ptrval << endl; // *ptrval = 9
    cout << "ptr = " << ptr << endl;         // ptr = 9

    return 0;
}