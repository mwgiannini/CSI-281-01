/**
 * @ Author: MW Giannini
 * @ Create Time: 2022-03-02 21:39:51
 * @ Course: CSI-281-01
 * @ Assignment: pa4
 * @ Certificate of Authenticity: I certify that this is entirely my own work, except where I have given
 * @ : fully-documented references to the work of others. I understand the definition and
 * @ ~: consequences of plagiarism and acknowledge that the assessor of this assignment
 * @ ~~: may, for the purpose of assessing this assignment:
 * @ ~~~: - Reproduce this assignment and provide a copy to another member of academic staff;
 * @ ~~~~: and/or
 * @ ~~~~~: - Communicate a copy of this assignment to a plagiarism checking service (which may
 * @ ~~~~~~: then retain a copy of this assignment on its database for the purpose of future
 * @ ~~~~~~~: plagiarism checking)
 * @ Description:
 */

#include "CodeTimer.h"
#include "searchingFunctions.h"
#include "sortingFunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

template <typename T>
void load(const std::string &file, T *array, int size)
{
    int i;
    std::ifstream in(file);

    for (i = 0; i < size; i++)
    {
        in >> array[i];
    }

    in.close();
}

void testSequential(int *dataset, int *keyList, int size, int numSearches)
{
    int i;

    for(i = 0; i < numSearches; i++)
        sequentialSearch(dataset, keyList[i], size);
}

void testBinary(int *dataset, int *keyList, int size, int numSearches)
{
    int i;

    quickSort(dataset, 0, size - 1);

    for(i = 0; i < numSearches; i++)
        binarySearch(dataset, keyList[i], 0, size - 1);
}

int main()
{
    // Size of the datasets being searched
    const int N1 = 100;
    const int N2 = 10000;
    const int N3 = 1000000;
    const int N[] = {N1, N2, N3};
    std::string N_FILE = "data/N.dat";

    // Number of searches being performed
    const int K1 = 10;
    const int K2 = 100;
    const int K3 = 10000;
    const int K4 = 1000000;
    const int K[] = {K1, K2, K3, K4};
    std::string K_FILE = "data/K.dat";

    CodeTimer timer;
    std::ofstream out("results.csv");
    out << std::fixed << std::setprecision(7);
    int i, k, n;
    double seqTime, binTime;

    for (i = 0; i < 3; i++)
    {
        for (k = 0; k < 4; k++)
        {
            out << "Number of Searches: " << K[k] << "\n";

            int *keyList = new int[K[k]];
            load(K_FILE, keyList, K[k]);

            for(n = 0; n < 3; n++)
            {
                out << N[n];

                int *dataset = new int[N[n]];
                load(N_FILE, dataset, N[n]);

                timer.start();
                testSequential(dataset, keyList, N[n], K[k]);
                seqTime = timer.read();

                out << "," << seqTime;

                timer.start();
                testBinary(dataset, keyList, N[n], K[k]);
                binTime = timer.read();

                out << "," << binTime << "\n";

                delete [] dataset;
            }

            delete [] keyList;
        }

        std::cout << "Completed " << i+1 << " set of tests.";

        out << "\n";
    }

    out.close();
    return 0;
}