/*  Author: MW Giannini
    Class: CSI-281-01
    Assignment: PA3
    Date Assigned: 02/10/2022
    Due Date: 02/11/2022
    Description: Template functions for sorting algorithms.
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
#ifndef SORTINGFUNCTIONS_H
#define SORTINGFUNCTIONS_H

/* Sort an array using the bubble sort algorithm

Pre: list and size provided
Post: list is sorted in ascending order
*/
template <typename T>
void bubbleSort(T list[], int size)
{
  bool swapped = true;
  while(swapped == true)
  {
    swapped = false;
    for(int i = 0; i < size-1; i++)
    {
      if(list[i+1] < list[i])
      {
        std::swap(list[i+1], list[i]);
        swapped = true;
      }
    }
  }
}

/* Sort an array using the insertion sort algorithm

Pre: list and size provided
Post: list is sorted in ascending order
*/
template <typename T>
void insertionSort(T list[], int size)
{
  for(int i = 1; i < size; i++)
  {
    int value = list[i];
    int j = i-1;
    while(j >= 0 && list[j] > value)
    {
      list[j+1] = list[j];
      j--;
    }
    list[j+1] = value;
  }
}

#endif