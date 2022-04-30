/*  Author: MW Giannini
    Class: CSI-281-01
    Assignment: Final Project
    Date Due: April 28th 2022
    Description: A program to encrypt a list of words using a codebook of word-code pairs.
    Designed to be more efficient than the version created in pa1 using a hash table.
    Certification of Authenticity:
    I certify that this is entirely my own work, except where I have given
    fully-documented references to the work of others.
*/

#include <iostream>
#include "ioFunctions.h"
#include "codebook.h"

using namespace std;

int main()
{
    const string CODEBOOK_FILENAME = "codes.txt";
    const string UNENCRYPTED_PATH = "unencrypted/";
    const string ENCRYPTED_PATH = "encrypted/";
    const string EXIT_CODE = "exit";

    Codebook codebook(CODEBOOK_FILENAME);
    codebook.displayCollisionMetrics();

    bool running = true;
    
    while (running)
    {
        string inputFileName = getInputFileName(EXIT_CODE, UNENCRYPTED_PATH);

        if (inputFileName == EXIT_CODE)
        {
            running = false;
        } 
        else
        {
            string outputFileName = getOutputFileName(inputFileName);
            encrypt(UNENCRYPTED_PATH + inputFileName, ENCRYPTED_PATH + outputFileName, codebook);
        }
    }
    return 0;
}