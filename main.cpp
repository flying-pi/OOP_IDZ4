#include <iostream>
#include "MyArray.h"

using namespace std;

int main() {
    int size = 0;
    cout << "Input size of array: ";
    cin >> size;
    short *array = new short[size];
    MyArray object(array, size);

    object.output->printMessage("Input size of array: ");
    object.output->printMessage(size);
    object.output->printMessage("\n");
//	object.generationElements();
    object.inputFromKeyboard();
    object.outputArray();
    object.output->printMessage("\n");
    object.output->printMessage("max element: ");
    object.output->printMessage(object.maxElementOfArray());
    object.output->printMessage("\n");
    object.output->printMessage("min element: ");
    object.output->printMessage(object.minElementOfArray());
    object.output->printMessage("\n");
    object.isPalindrome();
    object.bubbleSortInc();
    object.outputArray();
    object.bubbleSortDec();
    object.outputArray();
	object.getSum();
    delete  array;
	system("pause");
    return 0;
}