#include <iostream>
#include <fstream>
#include "tests.h"
#include "CodeTimer2/CodeTimer.h"

void TestArray::load(const std::string &fileName)
{
    std::ifstream in;
    in.open(fileName);

    for (int i = 0; i < mSize; i++)
    {
        in >> mArray[i];
    }

    in.close();
}

void TestArray::printArray()
{
    for (int i = 0; i < mSize - 1; i++)
        std::cout << mArray[i] << ",";
    std::cout << mArray[mSize - 1] << std::endl;
}

double TestArray::test(SortAlgorithm type)
{
    // Create a copy for testing
    int *tempArray = new int[mSize];
    for(int i = 0; i < mSize; i++)
        tempArray[i] = mArray[i];

    CodeTimer timer;

    switch (type)
    {
    case Bubble:
        bubbleSort(tempArray, mSize);
        break;
    case Merge:
        mergeSort(tempArray, 0, mSize - 1);
        break;
    case Quick:
        quickSort(tempArray, 0, mSize - 1);
        break;
    case Selection:
        selectionSort(tempArray, mSize);
        break;
    case Insertion:
        insertionSort(tempArray, mSize);
        break;
    case Shell:
        shellSort(tempArray, mSize);
        break;
    }

    delete [] tempArray;
    return timer.read();
}