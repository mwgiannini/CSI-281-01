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

#ifndef CODETIMER_H
#define CODETIMER_H

// For Windows OS
#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#undef max

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