#include <iostream>

int main()
{
    // Load the codebook into a container class
    const std::string CODEBOOK_FILENAME = "codes.txt";
    Codebook codebook(CODEBOOK_FILENAME);

    const std::string EXIT_CODE = "exit";
    while (true)
    {
        // Get input file name from the user and break if the name matches the exit code
        std::string inputFileName = getInputFileName();
        if (inputFileName == EXIT_CODE) break;

        // Load input file into an object of a class with members that can hold and encrypt the data
        EnigmaFile file(inputFileName);

        // Get output file name from user and save an encrypted file to the given location
        std::string outputFileName = getOutputFileName();
        file.encrypt(outputFileName);
    }

    return 0;
}