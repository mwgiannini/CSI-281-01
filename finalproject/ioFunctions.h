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

#ifndef IOFUNCTIONS_H
#define IOFUNCTIONS_H

#include <string>
#include "codebook.h"

using namespace std;

/*      Pre:  Given input and output file paths and a codebook
 *     Post:  A file containing an encrypted version of the message is written to the given location
 *  Purpose:  Encrypt a message using a codebook
 *********************************************************/
void encrypt(const string &inputFilePath, const string &outputFilePath, Codebook &codebook);

/*      Pre:  Input file is stored in the unencryptedPath directory
 *     Post:  Returned string is a valid filename or the exit code
 *  Purpose:  Prompt the user for an input file name
 *********************************************************/
string getInputFileName(const string &exitCode, const string &unencryptedPath);

/*      Pre:  Given an input file name
 *     Post:  Returns string straight from cin
 *  Purpose:  Prompt the user for an output file name
 *********************************************************/
string getOutputFileName(const string &inputFileName);

/*      Pre:  Given a file name to check
 *     Post:  Returns true if the given file exists
 *  Purpose:  Determine if a given file name is valid
 *********************************************************/
bool isValidFileName(const string &fileName);


/*      Pre:  Last period in file name is the beginning of the extension
 *     Post:  Finds the last period and returns a substring of the characters before it
 *            if there is no period, the file name is returned as is
 *  Purpose:  Remove the extension from a file name
 *********************************************************/
string removeExtension(const string &fileName);

/*      Pre:  None
 *     Post:  Clears cin and ignores everything in it
 *  Purpose:  Flush cin
 *********************************************************/
void flushCin();

#endif