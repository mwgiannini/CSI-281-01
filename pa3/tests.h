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

class TestArray
{
public:
    TestArray(int size)
    {
        this->size = size;
        array = new int[size];
    }
    TestArray(int size, const std::string &fileName) : TestArray(size)
    {
        load(fileName);
    }
    ~TestArray()
    {
        delete[] array;
    }

    /* Populate the test array with values from the given data file

    Pre: Provide fileName
    Post: Array contains data from file
    */
    void load(const std::string &fileName);

    /* Print the test array to the console.

    Pre: None
    Post: Array is printed to console
    */
    void printArray();

    /* Test sort a given sorting algorithm.

    Pre: Provide algorithm type
    Post: Return sort time in seconds
    */
    double test(SortAlgorithm type);

private:
    int *array;
    int size;
};

#endif