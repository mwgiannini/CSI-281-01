/*  Author: MW Giannini
    Class: CSI-281-01
    Assignment: PA3
    Date Assigned: 02/21/2022
    Due Date: 02/28/202
    Description: A struct for creating random arrays of integers.
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

#ifndef GENERATEDATA_H
#define GENERATEDATA_H

#include <random>
#include <iostream>
#include <fstream>
#include "sortingFunctions.h"

void generateDataFiles();
template <typename T>
void reverseArray(T array[], int size);
template <typename T>
void writeArray(T array[], int size, const std::string &fileName);

/* For creating test sorting data

Pre: None
Post: Six files are created with the integers for each test
*/
void generateDataFiles()
{
    const int SEED = 34;
    const int SIZE1 = 100;
    const int SIZE2 = 10000;
    const int SIZE3 = 1000000;
    const int MAX_VALUE = 10000;

    int *array3 = new int[SIZE3];
    int *array2 = new int[SIZE2];
    int *array1 = new int[SIZE1];

    srand(SEED);

    for (int i = 0; i < SIZE3; i++)
    {
        int value = rand() % MAX_VALUE + 1;

        array3[i] = value;
        if(i >= SIZE2) continue;
        array2[i] = value;
        if(i >= SIZE1) continue;
        array1[i] = value; 
    }

    writeArray(array3, SIZE3, "test-3-average.dat");
    writeArray(array2, SIZE2, "test-2-average.dat");
    writeArray(array1, SIZE1, "test-1-average.dat");

    quickSort(array1, 0, SIZE1 - 1);
    quickSort(array2, 0, SIZE2 - 1);
    quickSort(array3, 0, SIZE3 - 1);

    writeArray(array3, SIZE3, "test-3-best.dat");
    writeArray(array2, SIZE2, "test-2-best.dat");
    writeArray(array1, SIZE1, "test-1-best.dat");

    reverseArray(array1, SIZE1);
    reverseArray(array2, SIZE2);
    reverseArray(array3, SIZE3);

    writeArray(array3, SIZE3, "test-3-worst.dat");
    writeArray(array2, SIZE2, "test-2-worst.dat");
    writeArray(array1, SIZE1, "test-1-worst.dat");

    delete [] array3;
    delete [] array2;
    delete [] array1;
}

/* Reverse order of an array

Pre: Given array pointer and size
Post: array is reversed
*/
template <typename T>
void reverseArray(T array[], int size)
{
    int i, j;
    
    i = 0;
    j = size - 1;

    while(i < j)
    {
        std::swap(array[i], array[j]);
        i++;
        j--;
    }
}

/* Write an array to file

Pre: Given array pointer, size, and a fileName
Post: A file is written with array data
*/
template <typename T>
void writeArray(T array[], int size, const std::string &fileName)
{
    std::ofstream out;
    out.open(fileName);

    for (int i = 0; i < size; i++)
        out << array[i] << "\n";

    out.close();
}

#endif