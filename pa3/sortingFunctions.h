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
  int i;
  while(swapped)
  {
    swapped = false;
    for(i = 0; i < size - 1; i++)
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
  int value, i, j;
  for(i = 1; i < size; i++)
  {
    value = list[i];
    j = i - 1;
    while(j >= 0 && list[j] > value)
    {
      list[j+1] = list[j];
      j--;
    }
    list[j+1] = value;
  }
}

/* Sort an array using the selection sort algorithm

Pre: list and size provided
Post: list is sorted in ascending order
*/
template <typename T>
void selectionSort(T list[], int size)
{
  int minIndex, i, j;

  for(i = 0; i < size - 1; i++)
  {
    minIndex = i;

    for(j = i + 1; j < size; j++)
    {
      if(list[j] < list[minIndex])
        minIndex = j;
    }

    if(minIndex != i)
      std::swap(list[i], list[minIndex]);
  }
}

/* Sort an array using the shell sort algorithm

Pre: list and size provided
Post: list is sorted in ascending order
*/
template <typename T>
void shellSort(T list[], int size)
{
  int gap, i;

  gap = size / 2;

  while(gap > 0)
  {
    for(int i = 0; i < size - gap; i++)
    {
      if(list[i] > list[i + gap])
      {
        std::swap(list[i], list[i + gap]);
      }
    }

    gap /= 2;
  }

  bubbleSort(list, size);
}

#endif