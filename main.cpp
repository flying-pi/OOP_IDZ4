#include <iostream>
#include "MyArray.h"

using namespace std;

int main() {
    int size = 0;
    cout << "Input size of array: ";
    cin >> size;
    short *array = new short[size];
    MyArray object(array, size);

    //object.generationElements();
    object.inputFromKeyboard();

    for(int i = 0 ; i< size;i++){
        cout << array[i] << " ";
    }
    cout << '\n';
    cout << "max element: ";
    cout << object.maxElementOfArray() << '\n';
    cout << "min element: ";
    cout << object.minElementOfArray() << '\n';

//    object.bubbleSortInc();
//    for(int i = 0 ; i< size;i++){
//        cout << array[i] << " ";
//    }
//    cout << '\n';
//    object.bubbleSortDec();
//
//    for(int i = 0 ; i< size;i++){
//        cout << array[i] << " ";
//    }
//
//    cout << '\n';
    object.isPalindrome();
    return 0;
}