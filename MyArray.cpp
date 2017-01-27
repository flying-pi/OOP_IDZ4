//
// Created by Yura Braiko on 27.01.17.
//

#include <iostream>
#include "MyArray.h"

using namespace std;

MyArray::MyArray(short int *array, int size) {
    this->array = array;
    this->size = size;
}

void MyArray::inputFromKeyboard() {
    cout << "Input your array:\n";
    for (int i = 0; i < this->size; i++) {
        cout << "[" << i << "] = ";
        cin >> this->array[i];
    }
}

void MyArray::generationElements() {
    srand(time(NULL));
    for (int i = 0; i < this->size; i++) {
        this->array[i] = 32767 + rand() % 65535;
    }
}
