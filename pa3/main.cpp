/*  Author: MW Giannini
    Class: CSI-281-01
    Assignment: PA3
    Date Assigned: 02/10/2022
    Due Date: 02/11/2022
    Description: A stub driver to test sortingFunctions.h
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
#include "sortingFunctions.h"
#include "RandIntArray.h"

enum SortAlgorithm
{
  Bubble,
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
  case Selection:
    std::cout << "...Selection sort..." << std::endl;
    selectionSort(test.array, test.size);
    break;
  case Insertion:
    std::cout << "...Insertion sort..." << std::endl;
    insertionSort(test.array, test.size);
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

int main()
{
  int size = 1000;
  int max = 100;
  RandIntArray test(size, max);

  printTest(Bubble, test);
  printTest(Selection, test);
  printTest(Insertion, test);
  printTest(Shell, test);

  return 0;
}