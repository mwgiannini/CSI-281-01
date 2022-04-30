#ifndef CODEPAIR_H
#define CODEPAIR_H

#include <string>

using namespace std;

struct CodePair
{
    string mWord, mCode;

    CodePair(const string &word, const string &code)
    {
        mWord = word;
        mCode = code;
    }

    CodePair()
    {
        mWord = "";
        mCode = "";
    }
};

#endif