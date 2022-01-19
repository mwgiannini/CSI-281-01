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

#include <iostream>
#include <fstream>
#include "helper.h"

std::string getInputFileName(const std::string& exitCode)
{
    const std::string UNENCRYPTED_PATH = "unencrypted/";

    std::string inputPrompt = "Enter a file name to encrypt: ";
    std::string input;
    bool validFileName;
    do 
    {
        // Get file name from user
        std::cout << inputPrompt;
        std::cin >> input;
        if(input == exitCode) return input;

        // Check if the file name is valid
        validFileName = isValidFileName(UNENCRYPTED_PATH + input);
    } while(!validFileName);
    
    return UNENCRYPTED_PATH + input;
}

std::string getOutputFileName()
{
    const std::string ENCRYPTED_PATH = "encrypted/";

    std::string inputPrompt = "Enter a location to save the encrypted file: ";
    std::string input;

    std::cout << inputPrompt;
    std::cin >> input;
    
    return ENCRYPTED_PATH + input;
}

bool isValidFileName(const std::string& fileName)
{
    std::ifstream testOpen(fileName);
    return static_cast<bool>(testOpen);
}