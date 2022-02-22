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
    while (swapped)
    {
        swapped = false;
        for (i = 0; i < size - 1; i++)
        {
            if (list[i + 1] < list[i])
            {
                std::swap(list[i + 1], list[i]);
                swapped = true;
            }
        }
    }
}

/* Sort an array using the gnome sort algorithm
https://en.wikipedia.org/wiki/Gnome_sort
I chose this one because it has a cool name and it
is interesting how simple it is

Pre: list and size provided
Post: list is sorted in ascending order
*/
template <typename T>
void gnomeSort(T list[], int size)
{
    int i = 0;

    while (i < size)
    {
        if (i == 0 || list[i] >= list[i - 1])
            i++;
        else
        {
            std::swap(list[i], list[i - 1]);
            i--;
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
    for (i = 1; i < size; i++)
    {
        value = list[i];
        j = i - 1;
        while (j >= 0 && list[j] > value)
        {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = value;
    }
}

/* Merge two parts of a list in a sorted manner

Pre: list, inclusive bounds, and midpoint provided
Post: list is merged in a sorted manner between the bounds
*/
template <typename T>
void merge(T list[], int lowerBound, int mid, int upperBound)
{
    int size1, size2, i, j, k;

    size1 = mid - lowerBound + 1;
    size2 = upperBound - mid;

    T *tmp1 = new T[size1];
    T *tmp2 = new T[size2];

    for (i = 0; i < size1; i++)
        tmp1[i] = list[lowerBound + i];

    for (j = 0; j < size2; j++)
        tmp2[j] = list[mid + j + 1];

    i = 0;
    j = i;

    for (k = lowerBound; k < upperBound && i < size1 && j < size2; k++)
    {
        if (tmp1[i] <= tmp2[j])
        {
            list[k] = tmp1[i];
            i++;
        }
        else
        {
            list[k] = tmp2[j];
            j++;
        }
    }

    while (i < size1)
    {
        list[k] = tmp1[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        list[k] = tmp2[j];
        j++;
        k++;
    }

    delete[] tmp1;
    delete[] tmp2;
}

/* Sort an array using the merge sort algorithm

Pre: list and inclusive bounds provided
Post: list is sorted in ascending order between the bounds
*/
template <typename T>
void mergeSort(T list[], int lowerBound, int upperBound)
{
    int mid;

    if (lowerBound < upperBound)
    {
        mid = (lowerBound + upperBound) / 2;
        mergeSort(list, lowerBound, mid);
        mergeSort(list, mid + 1, upperBound);
        merge(list, lowerBound, mid, upperBound);
    }
}

/* Sort an array using the quick sort algorithm

Pre: list and inclusive bounds provided
Post: list is sorted in ascending order between the bounds
*/
template <typename T>
void quickSort(T list[], int lowerBound, int upperBound)
{
    int pivot, i, j;

    i = lowerBound;
    j = upperBound;

    pivot = list[(lowerBound + upperBound) / 2];

    while (i <= j)
    {
        while (list[i] < pivot)
            i++;
        while (list[j] > pivot)
            j--;

        if (i <= j)
        {
            std::swap(list[i], list[j]);
            i++;
            j--;
        }
    }

    if (lowerBound < j)
        quickSort(list, lowerBound, j);
    if (i < upperBound)
        quickSort(list, i, upperBound);
}

/* Sort an array using the selection sort algorithm

Pre: list and size provided
Post: list is sorted in ascending order
*/
template <typename T>
void selectionSort(T list[], int size)
{
    int minIndex, i, j;

    for (i = 0; i < size - 1; i++)
    {
        minIndex = i;

        for (j = i + 1; j < size; j++)
        {
            if (list[j] < list[minIndex])
                minIndex = j;
        }

        if (minIndex != i)
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

    while (gap > 0)
    {
        for (i = 0; i < size - gap; i++)
        {
            if (list[i] > list[i + gap])
            {
                std::swap(list[i], list[i + gap]);
            }
        }

        gap /= 2;
    }

    bubbleSort(list, size);
}

#endif