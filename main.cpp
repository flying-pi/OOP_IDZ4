#include <iostream>
#include "MyArray.h"

using namespace std;

int main() {
    int size = 0;
    cout << "Input size of array: ";
    cin >> size;
    short *array = new short[size];
    MyArray object(array, size);


    for(int i = 0 ; i< size;i++){
        cout << array[i] << " ";
    }

    return 0;
}