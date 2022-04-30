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

#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include "ioFunctions.h"
#include "CodeTimer.h"

using namespace std;

void encrypt(const string &inputFilePath, const string &outputFilePath, Codebook &codebook)
{
    ifstream file(inputFilePath);
    ofstream outfile(outputFilePath);
    
    string line, word;
    stringstream lineStream;

    CodeTimer timer;
    double encryptionTime;

    timer.start();
    while (!file.eof())
    {
        // Get each line as a string stream
        getline(file, line);
        lineStream = stringstream(line);

        // Print the line
        while (!lineStream.eof())
        {
            lineStream >> word;
            outfile << codebook.encode(word);
            if (!lineStream.eof()) outfile << " ";
        }

        // End the line
        if(!file.eof()) outfile << "\n";
    }
    encryptionTime = timer.read();
    
    cout << "File has been saved to " << outputFilePath << "." << endl;
    cout << "Encryption time: " << encryptionTime << " seconds." << endl;
}

string getInputFileName(const string& exitCode, const string &unencryptedPath)
{
    string input;
    bool validFileName;
    do 
    {
        // Get file name from user
        cout << "Enter a file name to encrypt: ";
        getline(cin, input);
        if(input == exitCode)
            break;

        // Check if the file name is valid
        validFileName = isValidFileName(unencryptedPath + input);
        if(!validFileName) 
            cout << "File does not exist!" << endl;
    } while(!validFileName);
    
    return input;
}

string getOutputFileName(const string &inputFileName)
{
    string outputFileName = "";

    // Give the user a few choices to meet the switch statement specification

    cout << "What would you like to call the encrypted file?" << endl;
    cout << "1. temp.txt" << endl;
    cout << "2. " + removeExtension(inputFileName) + "_encrypted.txt" << endl;
    cout << "3. Custom Name" << endl;

    int input;

    while(outputFileName == "")
    {
        input = 0;
        cin >> input;
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
                cout << "Enter a file name: ";
                getline(cin, outputFileName);
                break;

            default: // User input is invalid
                cout << "Please enter 1, 2, or 3" << endl;
        }
    }
    
    return outputFileName;
}

bool isValidFileName(const string& fileName)
{
    ifstream testOpen(fileName);
    return static_cast<bool>(testOpen);
}

string removeExtension(const string &fileName)
{
    int lastPeriod = fileName.find_last_of('.');
    if (lastPeriod == string::npos) return fileName;
    return fileName.substr(0, lastPeriod); 
}

void flushCin()
{
    cin.clear();
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}