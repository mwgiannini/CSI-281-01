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
#include <vector>
#include <string>
#include "codebook.h"
// A class for encrypting and decrypting messages

class Message
{
public:
    /*      Pre:  Given file exists with the proper message format
     *     Post:  Member array "words" contains the message and numWords, the number of words
     *  Purpose:  Construct a message object
     *********************************************************/
    Message(const std::string &inputFileName);

    /*      Pre:  None
     *     Post:  A file containing an encrypted version of the message is written to the given location
     *  Purpose:  Save an encrypted copy of the message
     *********************************************************/
    void encrypt(const std::string &outputFilePath, const Codebook &codebook);

private:
    static const int MAX_WORDS = 1000;
    std::string words[MAX_WORDS];
    int numWords;
};