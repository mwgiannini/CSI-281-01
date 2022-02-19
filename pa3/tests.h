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

/* Test sort an random array of integers against the give algorithm

Pre: The algorithm type and the RandIntArray are provided
Post: Test is printed to console
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


/* Compare the output of a number of sorting algorithms against quicksort

Pre: A test array is provided
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