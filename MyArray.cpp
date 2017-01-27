//
// Created by Yura Braiko on 27.01.17.
//

#include <iostream>
#include "MyArray.h"

using namespace std;

MyArray::MyArray(short int *array, int size) {
    this->array = array;
    this->size = size;
    output.open("/home/andrey/CLionProjects/OOP_IDZ4(2)/result.txt");
    if(!(output.is_open())) {
        output << "Error opening file!";
        cout << "Error opening file!";
        exit(1);
    }
}

void MyArray::inputFromKeyboard() {
    cout << "Input your array:\n";
    output << "Input your array:\n";
    for (int i = 0; i < this->size; i++) {
        cout << "[" << i << "] = ";
        output << "[" << i << "] = ";
        cin >> this->array[i];
        output << this->array[i] << '\n';
    }
}

void MyArray::generationElements() {
    srand(time(NULL));
    for (int i = 0; i < this->size; i++) {
        this->array[i] = 32767 + rand() % 65535;
    }
}

int MyArray::minElementOfArray() {
    int max = this->array[0];
    for (int i = 0; i < this->size; i++)
        if (this->array[i] > max)
            max = this->array[i];
    return max;
}

int MyArray::maxElementOfArray() {
    int min = this->array[0];
    for (int i = 0; i < this->size; i++)
        if (this->array[i] < min)
            min = this->array[i];
    return min;
}

void MyArray::bubbleSortInc() {
    int tmp = 0;
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size - 1; j++) {
            if (this->array[i] < this->array[j]) {
                tmp = this->array[i];
                this->array[i] = this->array[j];
                this->array[j] = tmp;
            }
        }
    }
}

void MyArray::bubbleSortDec() {
    int tmp = 0;
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size - 1; j++) {
            if (this->array[i] > this->array[j]) {
                tmp = this->array[i];
                this->array[i] = this->array[j];
                this->array[j] = tmp;
            }
        }
    }
}

MyArray::~MyArray() {
    delete[] this->array;
    output.close();

}

void MyArray::isPalindrome() {
    bool tmp = true;
    for (int leftPos = 0, rightPos = this->size - 1; leftPos < this->size / 2; leftPos++, rightPos--) {
        if (this->array[leftPos] != this->array[rightPos]) {
            tmp = false;
            cout << "Not palindrome\n";
            output << "Not palindrome\n";
            break;
        }
    }
    if (tmp) {
        cout << "Palindrome\n";
        output << "Palindrome\n";
    }
}

void MyArray::outputArray() {
    for(int i = 0; i < this->size; i++){
        cout << this->array[i] << " ";
        output << this->array[i] << " ";
    }
    cout << '\n';
    output << '\n';

}
