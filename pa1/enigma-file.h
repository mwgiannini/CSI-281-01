#include <vector>
#include <string>

class EnigmaFile
{
public:
    /*      Pre:  outputFileName is a valid filename
     *     Post:  A file is written with the encrypted data
     *  Purpose:  Write an encrypted copy of the file
     *********************************************************/
    void encrypt(std::string outputFileName);
private:
    std::vector<std::string> words;
};