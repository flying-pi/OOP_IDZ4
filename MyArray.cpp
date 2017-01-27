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

int MyArray::minElementOfArray() {
    int max = this->array[0];
    for(int i = 0; i < this->size;i++)
        if(this->array[i] > max)
            max = this->array[i];
    return max;
}

int MyArray::maxElementOfArray() {
    int min = this->array[0];
    for(int i = 0; i < this->size;i++)
        if(this->array[i] < min)
            min = this->array[i];
    return min;
}

void MyArray::bubbleSortInc() {
    int tmp = 0;
    for(int i = 0; i < this->size; i++){
        for(int j = 0; j < this->size -1; j++){
            if(this->array[i] < this->array[j]){
                tmp = this->array[i];
                this->array[i] = this->array[j];
                this->array[j] = tmp;
            }
        }
    }
}

void MyArray::bubbleSortDec() {
    int tmp = 0;
    for(int i = 0; i < this->size; i++){
        for(int j = 0; j < this->size -1; j++){
            if(this->array[i] > this->array[j]){
                tmp = this->array[i];
                this->array[i] = this->array[j];
                this->array[j] = tmp;
            }
        }
    }
}
