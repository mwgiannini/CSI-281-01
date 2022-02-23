#ifndef CODETIMER_H
#define CODETIMER_H

// For Windows OS
#if defined(_WIN32) || defined(WIN32)
#include <windows.h>

// For Unix based OS
#else
#include <sys/time.h>
#endif


class CodeTimer
{
public:
    CodeTimer();

    /* Start the timer

    Pre: None
    Post: Record the current time
    */
    void start();

    /* Read the timer

    Pre: None
    Post: Return the time in seconds since start was last called
    If start was never called, return the age of the timer object
    */
    double read();
private:
#if defined(_WIN32) || defined(WIN32)
    LARGE_INTEGER startTime, endTime, frequency;
#else
    timeval startTime, endTime;
#endif
};

#endif