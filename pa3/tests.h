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

#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include "CodeTimer/CodeTimer.h"
#include "sortingFunctions.h"

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

/* Populate an array with values from the given data file

Pre: Provide array, size, and file name
Post: Array contains data from file
*/
template <typename T>
void readArray(T array[], int size, const std::string &fileName)
{
  std::ifstream in;
  in.open(fileName);

  for(int i = 0; i < size; i++)
  {
    in >> array[i];
  }
}

/* Test a given sorting algorithm on the given data

Pre: Provide array, size, and algorithm
Post: Return elapsed time in seconds
*/
template <typename T>
double testSort(T array[], int size, SortAlgorithm type)
{
  CodeTimer timer;

  switch(type)
  {
    case Bubble:
      bubbleSort(array, size);
    case Merge:
      mergeSort(array, 0, size - 1);
    case Quick:
      quickSort(array, 0, size - 1);
    case Selection:
      selectionSort(array, size);
    case Insertion:
      insertionSort(array, size);
    case Shell:
      shellSort(array, size);
  }

  return timer.read();
}

#endif