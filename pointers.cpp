#include <iostream>

using namespace std;

int main()
{
    int val = 9;
    int *ptrval = &val; // Указатель указывает на область памяти, извлекая из неё значение
    int &ptr = val;

    cout << "val = " << val << endl;         // val = 9
    cout << "&val = " << &val << endl;       // &val = 0x61fe0c
    cout << "ptrval = " << ptrval << endl;   // ptrval = 0x61fe0c
    cout << "*ptrval = " << *ptrval << endl; // *ptrval = 9
    cout << "ptr = " << ptr << endl;         // ptr = 9
    cout << "*&val = " << *&val << endl;     // *&val = 9
    *ptrval = 8;
    cout << "val = " << val << endl; // val = 8

    return 0;
}