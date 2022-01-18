#include <string>

struct WordCodePair
{
    std::string word;
    int code;
};

class Codebook
{
public:
    /*      Pre:  fileName is a valid filename
     *     Post:  This object's member, codebook points to the data from the given file
     *  Purpose:  Construct a Codebook object
     *********************************************************/
    Codebook(std::string fileName);

private:
    static WordCodePair* codebook;
};