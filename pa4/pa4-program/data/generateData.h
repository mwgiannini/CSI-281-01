/**
 * @ Author: MW Giannini
 * @ Create Time: 2022-03-03 18:13:06
 * @ Course: CSI-281-01
 * @ Assignment: PA4
 * @ Certificate of Authenticity: I certify that this is entirely my own work, except where I have given
 * @ : fully-documented references to the work of others. I understand the definition and
 * @ ~: consequences of plagiarism and acknowledge that the assessor of this assignment
 * @ ~~: may, for the purpose of assessing this assignment:
 * @ ~~~: - Reproduce this assignment and provide a copy to another member of academic staff;
 * @ ~~~~: and/or
 * @ ~~~~~: - Communicate a copy of this assignment to a plagiarism checking service (which may
 * @ ~~~~~~: then retain a copy of this assignment on its database for the purpose of future
 * @ ~~~~~~~: plagiarism checking)
 * @ Description: Functions for generating datasets.
 */

#ifndef GENERATEDATA_H
#define GENERATEDATA_H

#include <iostream>
#include <fstream>

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


/* For creating test data of random integers

Pre: Given seed, size, maxValue, and file name.
Post: A file of the given length is written with the given filename containing integers 
from 1 - max value inclusive. The integers are random, generated with the given seed.
*/
void generateDataFile(int seed, int size, int maxValue, const std::string &fileName)
{
    const std::string fileExtension = ".dat";

    int *array = new int[size];

    std::srand(seed);

    for (int i = 0; i < size; i++)
        array[i] = std::rand() % maxValue + 1;

    writeArray(array, size, fileName);

    delete [] array;
}

#endif