/*  Author: MW Giannini
    Class: CSI-281-01
    Assignment: PA3
    Date Assigned: 02/10/2022
    Due Date: 02/11/2022
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

#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include "sortingFunctions.h"
#include "RandIntArray.h"

enum SortAlgorithm
{
  Bubble,
  Merge,
  Quick,
  Selection,
  Insertion,
  Shell
};

/* Print an array to the console.

Pre: Array and size provided
Post: Array is printed to console
*/
template <typename T>
void printArray(const T list[], int size)
{
  for (int i = 0; i < size - 1; i++)
    std::cout << list[i] << ",";
  std::cout << list[size - 1] << std::endl;
}

/* Print a random array of integers before and after sorting

Pre: The algorithm type and the RandIntArray are provided
Post: The test is printed to console
*/
void printTest(SortAlgorithm type, RandIntArray test)
{
  std::cout << "\n\n";
  printArray(test.array, test.size);
  std::cout << "\n";
  switch (type)
  {
    case Bubble:
        std::cout << "...Bubble sort..." << std::endl;
        bubbleSort(test.array, test.size);
        break;
    case Insertion:
        std::cout << "...Insertion sort..." << std::endl;
        insertionSort(test.array, test.size);
        break;
    case Merge:
        std::cout << "...Merge sort..." << std::endl;
        mergeSort(test.array, 0, test.size - 1);
        break;
    case Quick:
        std::cout << "...Quick sort..." << std::endl;
        quickSort(test.array, 0, test.size - 1);
        break;
    case Selection:
        std::cout << "...Selection sort..." << std::endl;
        selectionSort(test.array, test.size);
        break;
    case Shell:
        std::cout << "...Shell sort..." << std::endl;
        shellSort(test.array, test.size);
        break;
  }
  std::cout << "\n";
  printArray(test.array, test.size);
  std::cout << "\n\n";
}


/* Compare the output of a number of sorting algorithms

Pre: A test RandIntArray is provided
Post: Returns true if all sorting algorithms produce the same sorted array
*/
bool sortTest(RandIntArray test)
{
    RandIntArray bubbleTest = test;
    RandIntArray insertionTest = test;
    RandIntArray mergeTest = test;
    RandIntArray quickTest = test;
    RandIntArray selectionTest = test;
    RandIntArray shellTest = test;

    bubbleSort(bubbleTest.array, bubbleTest.size);
    insertionSort(insertionTest.array, insertionTest.size);
    mergeSort(mergeTest.array, 0, mergeTest.size - 1);
    quickSort(quickTest.array, 0, quickTest.size - 1);
    selectionSort(selectionTest.array, selectionTest.size);
    shellSort(shellTest.array, shellTest.size);

    bool passed = quickTest == bubbleTest && 
                quickTest == insertionTest && 
                quickTest == mergeTest && 
                quickTest == selectionTest && 
                quickTest == shellTest;

    return passed;
}

#endif