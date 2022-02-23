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