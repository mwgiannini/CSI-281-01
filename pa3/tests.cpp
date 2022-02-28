/*  Author: MW Giannini
    Class: CSI-281-01
    Assignment: PA3
    Date Assigned: 02/21/2022
    Due Date: 02/28/202
    Description: For tests on the pa3 sorting algorithms
    Certification of Authenticity:
    I certify that this is entirely my own work, except where I have given
    fully-documented references to the work of others. I understand the definition and
    consequences of plagiarism and acknowledge that the assessor of this assignment
    may, for the purpose of assessing this assignment:
    - Reproduce this assignment and provide a copy to another member of academic staff;
    and/or
    - Communicate a copy of this assignment to a plagiarism checking service (which may
    then retain a copy of this assignment on its database for the purpose of future
    plagiarism checking)
*/

#include <iostream>
#include <fstream>
#include "tests.h"
#include "CodeTimer/CodeTimer.h"

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