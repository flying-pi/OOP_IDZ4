//
// Created by Yura Braiko on 27.01.17.
//

#ifndef OOP_IDZ4_MYARRAY_H
#define OOP_IDZ4_MYARRAY_H


#include <fstream>

class MyArray {

public:
    MyArray(short int *array, int size);

    void inputFromKeyboard();

    void generationElements();

    int minElementOfArray();

    int maxElementOfArray();

    void bubbleSortInc();

    void bubbleSortDec();

    ~MyArray();

    void isPalindrome();

    void outputArray();

    std::ofstream output;
private:

    short *array;
    int size;
};


#endif //OOP_IDZ4_MYARRAY_H
