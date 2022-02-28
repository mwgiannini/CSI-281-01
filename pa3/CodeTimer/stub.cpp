/*  Author: MW Giannini
    Class: CSI-281-01
    Assignment: PA3
    Date Assigned: 02/21/2022
    Due Date: 02/28/2022
    Description: A simple interface for timing code execution on both unix and windows OS.
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

#include <iostream>
#include <iomanip>
#include "CodeTimer.h"

int main()
{
    CodeTimer timer;

    for(int i = 0; i < 5000; i++)
        std::cout << "test\n";

    std::cout << std::fixed << std::setprecision(15);
    std::cout << "It took " << timer.read() << " seconds to print 5,000 lines\n\n";

    timer.start();

    std::cout << "test\n";

    std::cout << std::fixed << std::setprecision(15);
    std::cout << "It took " << timer.read() << " seconds to print 1 lines\n";

    return 0;
}
