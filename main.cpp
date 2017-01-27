#include <iostream>
#include "MyArray.h"

using namespace std;

int main() {
    int size = 0;
    cout << "Input size of array: ";
    cin >> size;
    short *array = new short[size];
    MyArray object(array, size);
    object.output << "Input size of array: ";
    object.output << size << '\n';
	object.generationElements();
    //object.inputFromKeyboard();
    object.outputArray();
    cout << '\n';
    cout << "max element: ";
    cout << object.maxElementOfArray() << '\n';
    cout << "min element: ";
    cout << object.minElementOfArray() << '\n';
    object.output << '\n';
    object.output << "max element: ";
    object.output << object.maxElementOfArray() << '\n';
    object.output << "min element: ";
    object.output << object.minElementOfArray() << '\n';
    object.isPalindrome();
    object.bubbleSortInc();
    object.outputArray();
    object.bubbleSortDec();
    object.outputArray();
	object.getSum();
	system("pause");
    return 0;
}