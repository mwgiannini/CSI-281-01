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

#include <fstream>
#include <iostream>
#include <sstream>
#include "message.h"
#include "codebook.h"

Message::Message(const std::string &inputFileName)
{
    std::ifstream file(inputFileName);
    this->numWords = 0;

    while (!file.eof())
    {
        file >> words[numWords];
        numWords++;
    }
}

void Message::encrypt(const std::string &outputFilePath, const Codebook &codebook)
{
    std::stringstream output;
    for (int i = 0; i < numWords; i++)
    {
        output << codebook.retrieveCodeFor(words[i]) << " ";
    }

    std::ofstream outfile(outputFilePath);
    outfile << output.str();
    
    std::cout << "File has been saved to " << outputFilePath << "." << std::endl;
}