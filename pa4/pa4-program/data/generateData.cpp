/**
 * @ Author: MW Giannini
 * @ Create Time: 2022-03-03 18:27:47
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
 * @ Description: Driver to generate datasets.
 */

#include "generateData.h"

int main()
{
    const int SIZE1 = 100;
    const int SIZE2 = 10000;
    const int SIZE3 = 1000000;
    const int DATA_SEED = 34;
    const int KEY_SEED = 35;
    const int MAX_VALUE = 10000;

    generateDataFile(DATA_SEED, SIZE1, MAX_VALUE, "N1.dat");
    generateDataFile(DATA_SEED, SIZE2, MAX_VALUE, "N2.dat");
    generateDataFile(DATA_SEED, SIZE3, MAX_VALUE, "N3.dat");

    generateDataFile(KEY_SEED, SIZE1, MAX_VALUE, "K1.dat");
    generateDataFile(KEY_SEED, SIZE2, MAX_VALUE, "K2.dat");
    generateDataFile(KEY_SEED, SIZE3, MAX_VALUE, "K3.dat");

    return 0;
}