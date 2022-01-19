/*  Author: MW Giannini
    Class: CSI-281-01
    Assignment: pa1
    Date Assigned: January 17th 2022
    Due Date:  January 24th by 11:30am 
    Description: A program to encrypt a list of words using a codebook of word-code pairs.
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

#pragma once
#include <string>
// Helper functions

/*      Pre:  None
 *     Post:  Returned string is a valid filename or the exit code
 *  Purpose:  Prompt the user for an input file name
 *********************************************************/
std::string getInputFileName(const std::string& exitCode);

/*      Pre:  None
 *     Post:  None
 *  Purpose:  Prompt the user for an output file name
 *********************************************************/
std::string getOutputFileName();


/*      Pre:  None
 *     Post:  Returns true if the given file exists
 *  Purpose:  Determine if a given file name is valid
 *********************************************************/
bool isValidFileName(const std::string& fileName);