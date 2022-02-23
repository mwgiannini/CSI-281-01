/*  Author: MW Giannini
    Class: CSI-281-01
    Assignment: PA3
    Date Assigned: 02/21/2022
    Due Date: 02/28/202
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

#include "generateData.h"
#include "tests.h"
#include "CodeTimer2/CodeTimer.h"
#include <assert.h>
#include <iomanip>
#include <sstream>
#include <fstream>

int main()
{
    std::cout << std::fixed << std::setprecision(20);

    int testSize, testCase, algorithm;
    double result;

    int N[] =                       { 100, 10000, 1000000 };
    std::string cases[] =           { "average", "best", "worst" };
    std::string algorithms[] =      { "Bubble", "Merge", "Quick", "Selection", "Insertion", "Shell" };

    for(testSize = 0; testSize < 2; testSize++)
    {
        for(testCase = 0; testCase < 3; testCase++)
        {
            std::stringstream file;
            file << "test-" << (testSize + 1) << "-" << cases[testCase] << ".dat";
            std::cout << "Testing file: " + file.str() + "\n";

            TestArray current(N[testSize], file.str()); // Use TestArray class to make testing easy

            for(algorithm = 0; algorithm < 6; algorithm++)
            {
                result = current.test(static_cast<SortAlgorithm>(algorithm));

                std::cout << "The " << algorithms[algorithm] << " sort took " << result << " seconds.\n";
            }
        }
    }

    return 0;
}