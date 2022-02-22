/*  Author: MW Giannini
    Class: CSI-281-01
    Assignment: PA3
    Date Assigned: 02/21/2022
    Due Date: 02/28/2022
    Description: A simple interface for using the chrono library to time code execution.
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

#include "CodeTimer.h"

#include <chrono>

CodeTimer::CodeTimer()
{
    startTime = std::chrono::high_resolution_clock::now();
}

void CodeTimer::start()
{
    startTime = std::chrono::high_resolution_clock::now();
}

double CodeTimer::read()
{
    double NANOSECONDS = 1000000000.0; // Nanoseconds in a second
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime) / NANOSECONDS;

    return elapsed.count();
}