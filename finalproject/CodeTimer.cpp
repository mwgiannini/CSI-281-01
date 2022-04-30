/*  Author: MW Giannini
    Class: CSI-281-01
    Assignment: Final Project
    Date Due: April 28th 2022
    Description: A program to encrypt a list of words using a codebook of word-code pairs.
    Designed to be more efficient than the version created in pa1.
    Certification of Authenticity:
    I certify that this is entirely my own work, except where I have given
    fully-documented references to the work of others.
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

    startTimeInMicroSec = startTime.tv_sec + (startTime.tv_usec * 1000000.0);
    endTimeInMicroSec = endTime.tv_sec + (endTime.tv_usec * 1000000.0);
#endif

    return endSeconds - startSeconds;
}