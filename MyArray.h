//
// Created by Yura Braiko on 27.01.17.
//

#ifndef OOP_IDZ4_MYARRAY_H
#define OOP_IDZ4_MYARRAY_H


class MyArray {

public:
    MyArray(short int * array, int size);
    void inputFromKeyboard();
    void generationElements();
    int minElementOfArray();
    int maxElementOfArray();
    void bubbleSortInc();
    void bubbleSortDec();
private:
    short *array;
    int size;
};


#endif //OOP_IDZ4_MYARRAY_H
