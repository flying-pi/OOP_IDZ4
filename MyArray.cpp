//
// Created by Yura Braiko on 27.01.17.
//

#include <iostream>
#include "MyArray.h"
#include <ctime>

using namespace std;

MyArray::MyArray(short int *array, int size) {
    this->array = array;
    this->size = size;
    output = new PrintComposer();
    output->addConsolePrinter();
    output->addFilePrinter();
}

void MyArray::inputFromKeyboard() {
    output->printMessage("Input your array:\n");
    for (int i = 0; i < this->size; i++) {
        output->printMessage("[");
        output->printMessage(i);
        output->printMessage("] :: ");
        cin >> this->array[i];

        output->printMessage(this->array[i]);
        output->printMessage("\n");
    }
}

void MyArray::generationElements() {
    srand(time(NULL));
    for (int i = 0; i < this->size; i++) {
        this->array[i] = rand() % 65535 - 32767;
    }
}

short int MyArray::minElementOfArray() {
    int max = this->array[0];
    for (int i = 0; i < this->size; i++)
        if (this->array[i] > max)
            max = this->array[i];
    return max;
}

short int MyArray::maxElementOfArray() {
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
    delete output;

}

void MyArray::isPalindrome() {
    bool tmp = true;
    for (int leftPos = 0, rightPos = this->size - 1; leftPos < this->size / 2; leftPos++, rightPos--) {
        if (this->array[leftPos] != this->array[rightPos]) {
            tmp = false;
            output->printMessage("Not palindrome\n");
            break;
        }
    }
    if (tmp) {
        output->printMessage("Palindrome\n");
    }
}

void MyArray::outputArray() {
    for (int i = 0; i < this->size; i++) {
        output->printMessage(this->array[i]);
        output->printMessage(" ");
    }

    output->printMessage("\n");

}

short int MyArray::getSum() {
    short int result = 0;
    for (int i = 0; i < size; i++) {
        short int a = array[i];
        char isOverflow = 0;
        cout << result << endl;
        __asm
        {
        mov ax, a
        mov cx, result
        add ax, cx
        jo overwlow
        mov result, ax
        jmp done
        overwlow :
        mov isOverflow, 1
        done :

        }
        if (isOverflow == 1) {
            output->printMessage("catch overflow when calculate sum of array items\n");
            return result;
        }

    }

    output->printMessage("sum of array: ");
    output->printMessage(result);
    output->printMessage("\n");
    return result;
}
