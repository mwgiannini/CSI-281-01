/*  Author: Legolas
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

/*      Pre:  Input file is stored in the unencryptedPath directory
 *     Post:  Returned string is a valid filename or the exit code
 *  Purpose:  Prompt the user for an input file name
 *********************************************************/
std::string getInputFileName(const std::string &exitCode, const std::string &unencryptedPath);

/*      Pre:  None
 *     Post:  Returns string straight from cin
 *  Purpose:  Prompt the user for an output file name
 *********************************************************/
std::string getOutputFileName(const std::string &inputFileName);

/*      Pre:  None
 *     Post:  Returns true if the given file exists
 *  Purpose:  Determine if a given file name is valid
 *********************************************************/
bool isValidFileName(const std::string &fileName);


/*      Pre:  Last period in file name is the beginning of the extension
 *     Post:  Finds the last period and returns a substring of the characters before it
 *            if there is no period, the file name is returned as is
 *  Purpose:  Remove the extension from a file name
 *********************************************************/
std::string removeExtension(const std::string &fileName);

/*      Pre:  None
 *     Post:  Clears cin and ignores everything in it
 *  Purpose:  Flush cin
 *********************************************************/
void flushCin();