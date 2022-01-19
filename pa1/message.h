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
#include <vector>
#include <string>
#include "codebook.h"
// A class for encrypting and decrypting messages

class Message
{
public:
    /*      Pre:  inputFileName is a valid fileName
     *     Post:  File message is loaded into an array of words
     *  Purpose:  Construct a message object
     *********************************************************/
    Message(const std::string& inputFileName);

    /*      Pre:  none
     *     Post:  A file is written with the encrypted data
     *  Purpose:  Write an encrypted copy of the file
     *********************************************************/
    void encrypt(const std::string &outputFileName, const Codebook &codebook);
    
private:
    static const int MAX_WORDS = 1000;
    std::string words[MAX_WORDS];
    int numWords;
};