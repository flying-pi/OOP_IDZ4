//
// Created by Yura Braiko on 27.01.17.
//

#ifndef OOP_IDZ4_MYARRAY_H
#define OOP_IDZ4_MYARRAY_H


#include <fstream>
#include "OutPrinter.h"

class MyArray {

public:
    //не коректно задано задание поскольку в классе,  отвечающем за работу с массивом пристсвует
    // необходимость работы с файлами. Нарушение принципа единичной ответствености
    MyArray(short int *array, int size);

    void inputFromKeyboard();

    void generationElements();

	short int minElementOfArray();

	short int maxElementOfArray();

    void bubbleSortInc();

    void bubbleSortDec();

    ~MyArray();

    void isPalindrome();

    void outputArray();

	short int getSum();

    PrintComposer *output;
private:

    short *array;
    int size;
};


#endif //OOP_IDZ4_MYARRAY_H
