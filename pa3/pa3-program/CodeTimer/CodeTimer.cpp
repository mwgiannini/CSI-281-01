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

#include "CodeTimer.h"

CodeTimer::CodeTimer()
{
#if defined(_WIN32) || defined(WIN32)
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&startTime);
#else
    gettimeofday(&startTime, NULL);
#endif
}

void CodeTimer::start()
{
#if defined(_WIN32) || defined(WIN32)
    QueryPerformanceCounter(&startTime);
#else
    gettimeofday(&startTime, NULL);
#endif
}

double CodeTimer::read()
{
    double startSeconds, endSeconds;

#if defined(_WIN32) || defined(WIN32)
    QueryPerformanceCounter(&endTime);

    startSeconds = static_cast<double>(startTime.QuadPart) / static_cast<double>(frequency.QuadPart);
    endSeconds = static_cast<double>(endTime.QuadPart) / static_cast<double>(frequency.QuadPart);
#else
    gettimeofday(&endTime, NULL);

    startSeconds = startTime.tv_sec + (startTime.tv_usec / 1000000.0);
    endSeconds = endTime.tv_sec + (endTime.tv_usec / 1000000.0);
#endif

    return endSeconds - startSeconds;
}