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
    output.open("./result.txt");
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

short int MyArray::
getSum()
{
	short int result = 0;
	for (int i = 0;i < size;i++) {
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
			cout << "catch overflow when calculate sum of array items\n";
			output << "catch overflow when calculate sum of array items\n";
			return result;
		}
	
	}
	cout << "sum of array == " << result << "\n";
	output << "sum of array == " << result << "\n";
	return 0;
}
