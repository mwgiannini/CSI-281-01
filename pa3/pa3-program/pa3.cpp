/*  Author: MW Giannini
    Class: CSI-281-01
    Assignment: PA3
    Date Assigned: 02/21/2022
    Due Date: 02/28/202
    Description: Main function to test pa3 algorithms
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

#include "tests.h"
#include "CodeTimer/CodeTimer.h"
#include <assert.h>
#include <iomanip>
#include <sstream>
#include <fstream>

int main()
{
    int testSize, testCase, algorithm;
    double result;

    std::ofstream resultFile;
    resultFile.open("results.dat");
    resultFile << std::fixed << std::setprecision(20);

    int N[] =                       { 100, 10000, 1000000 };
    std::string cases[] =           { "average", "best", "worst" };
    std::string algorithms[] =      { "Bubble", "Merge", "Quick", "Selection", "Insertion", "Shell" };

    for(testSize = 0; testSize < 3; testSize++)
    {
        for(testCase = 0; testCase < 3; testCase++)
        {
            std::stringstream testFile;
            testFile << "test-" << (testSize + 1) << "-" << cases[testCase] << ".dat";

            // Use TestArray class to conduct tests
            TestArray testArray(N[testSize], testFile.str());
            
            resultFile << "Testing file: " + testFile.str() + "\n";

            for(algorithm = 0; algorithm < 6; algorithm++)
            {
                result = testArray.test(static_cast<SortAlgorithm>(algorithm));

                resultFile << "    ";
                resultFile << std::left << std::setw(15) << algorithms[algorithm];
                resultFile << std::right << std::setw(30) << result << " seconds\n";
            }
        }
    }

    resultFile.close();
    return 0;
}