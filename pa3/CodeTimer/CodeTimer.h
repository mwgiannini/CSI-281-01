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

#ifndef CODETIMER_H
#define CODETIMER_H

#include <chrono>

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
    std::chrono::time_point<std::chrono::steady_clock> startTime;
};

#endif