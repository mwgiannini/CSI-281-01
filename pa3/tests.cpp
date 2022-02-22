#include <iostream>
#include <fstream>
#include "tests.h"

void TestArray::load(const std::string &fileName)
{
    std::ifstream in;
    in.open(fileName);

    for (int i = 0; i < size; i++)
    {
        in >> array[i];
    }

    in.close();
}

void TestArray::printArray()
{
    for (int i = 0; i < size - 1; i++)
        std::cout << array[i] << ",";
    std::cout << array[size - 1] << std::endl;
}

double TestArray::test(SortAlgorithm type)
{
    // Create a copy for testing
    int *tempArray = new int[size];
    for(int i = 0; i < size; i++)
        tempArray[i] = array[i];

    CodeTimer timer;

    switch (type)
    {
    case Bubble:
        bubbleSort(tempArray, size);
    case Merge:
        mergeSort(tempArray, 0, size - 1);
    case Quick:
        quickSort(tempArray, 0, size - 1);
    case Selection:
        selectionSort(tempArray, size);
    case Insertion:
        insertionSort(tempArray, size);
    case Shell:
        shellSort(tempArray, size);
    }

    delete [] tempArray;
    return timer.read();
}