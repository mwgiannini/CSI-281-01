/*  Author: MW Giannini
    Class: CSI-281-01
    Assignment: PA3
    Date Assigned: 02/10/2022
    Due Date: 02/11/2022
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

#ifndef RANDINTARRAY_H
#define RANDINTARRAY_H

#include <random>

/* For creating test arrays to sort.

I used a struct to manage the deleting of the dynamic array
When constructing an RandIntArray object, a dynamic array of the given size
is created and populated with psuedo random integers bounded (1, max) inclusive
*/
struct RandIntArray
{
    int* array;
    int size;

    RandIntArray(int size, int max)
    {
        this->array = new int(size);
        this->size = size;

        for(int i = 0; i < size; i++)
            this->array[i] = rand() % max + 1;
    }
    ~RandIntArray()
    {
        delete [] this->array;
    }
};

#endif