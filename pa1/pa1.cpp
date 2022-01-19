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
#include "codebook.h"
#include "message.h"
#include "helper.h"

int main()
{
    const std::string CODEBOOK_FILENAME = "codes.txt";
    const std::string EXIT_CODE = "exit";

    // Load the codebook into a linked list
    Codebook codebook(CODEBOOK_FILENAME);

    while (true)
    {
        // Get input file name from the user
        std::string inputFileName = getInputFileName(EXIT_CODE);
        if (inputFileName == EXIT_CODE)
            break;

        // Create message object using given file
        Message message(inputFileName);

        // Save a encrypted version of the message to the given location
        std::string outputFileName = getOutputFileName();
        message.encrypt(outputFileName, codebook);
    }

    return 0;
}