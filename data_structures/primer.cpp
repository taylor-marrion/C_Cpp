#include <iostream> // Instead of <stdio.h>
#include <string>
using namespace std;

namespace space1
{ 
    int x, y;
}

namespace space2
{ 
    int x, y;
}

void changeX(int& x) {
    x = 100;
    cout << "In changeX, the local variable x is at memory location  " << &x << endl;
}

int main()
{
    space1::x = 10;
    space2::x = 20;

    cout << "Space1's x value is " << space1::x << endl;
    cout << "Space2's x value is " << space2::x << endl;

    int x, y;
    char c;

    cout << "Please enter two integers and a character: ";
    cin >> x >> y >> c;

    cout << "You typed " << x << ", " << y << ", and " << c << endl;

    int* ptr= new int;
    cout << "ptr has the memory address " << ptr << " stored." << endl;
    *ptr = 25;
    cout << "ptr dereferenced is holding " << *ptr << endl;
    delete ptr;

    int size;
    cout << "How big would you like your array: ";
    cin >> size;
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = i*2;
        cout << array[i] << "  ";
    }
    cout << endl;
    delete[] array;

    x = 5;
    cout << "The memory address of x in main is " << &x << endl;
    cout << "Before the function call, x = " << x << endl;
    changeX(x);
    cout << "After the function call, x = " << x << endl;

    string myStr;
    myStr = "Taylor Marrion";
    cout << "My name is " << myStr << endl;

    return 0;
}