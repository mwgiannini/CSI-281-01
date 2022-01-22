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

#include <iostream>
#include <fstream>
#include <limits>
#include "helper.h"

std::string getInputFileName(const std::string& exitCode, const std::string &unencryptedPath)
{
    std::string input;
    bool validFileName;
    do 
    {
        // Get file name from user
        std::cout << "Enter a file name to encrypt: ";
        getline(std::cin, input);
        if(input == exitCode) return input;

        // Check if the file name is valid
        validFileName = isValidFileName(unencryptedPath + input);
        if(!validFileName) std::cout << "File does not exist!" << std::endl;
    } while(!validFileName);
    
    return input;
}

std::string getOutputFileName(const std::string &inputFileName)
{
    std::string outputFileName = "";

    // Give the user a few choices to meet the switch statement specification

    std::cout << "What would you like to call the encrypted file?" << std::endl;
    std::cout << "1. temp.txt" << std::endl;
    std::cout << "2. " + removeExtension(inputFileName) + "_encrypted.txt" << std::endl;
    std::cout << "3. Custom Name" << std::endl;

    int input;

    while(outputFileName == "")
    {
        input = 0;
        std::cin >> input;
        flushCin();
        switch(input)
        {
            case 1:
                outputFileName = "temp.txt";
                break;

            case 2:
                outputFileName = removeExtension(inputFileName) + "_encrypted.txt";
                break;

            case 3:
                std::cout << "Enter a file name: ";
                getline(std::cin, outputFileName);
                break;

            default: // User input is invalid
                std::cout << "Please enter 1, 2, or 3" << std::endl;
        }
    }
    
    return outputFileName;
}

bool isValidFileName(const std::string& fileName)
{
    std::ifstream testOpen(fileName);
    return static_cast<bool>(testOpen);
}

std::string removeExtension(const std::string &fileName)
{
    int lastPeriod = fileName.find_last_of('.');
    if (lastPeriod == std::string::npos) return fileName;
    return fileName.substr(0, lastPeriod); 
}

void flushCin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}