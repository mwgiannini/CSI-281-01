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
#include <string>
#include "codebook.h"
#include "queue.h"

using namespace std;

Codebook::Codebook(const string &fileName)
{
    int n, i;
    
    mNumCollisions = 0, mNodesWithTenCollisions = 0,
    mMaxCollisionsAtOneIndex = 0;

    mNumPairs = findSize(fileName);
    n = static_cast<int>(mNumPairs * 2);

    mHashTable = new CollisionQueue* [n];
    for(i = 0; i < n; i++)
    {
        mHashTable[i] = new CollisionQueue();
    }
    
    loadFile(fileName);
}

Codebook::~Codebook()
{
    for(int i = 0; i < mNumPairs; i++)
    {
        if (mHashTable[i] != NULL)
            delete mHashTable[i];
    }
    delete mHashTable;
}

void Codebook::displayCollisionMetrics()
{
    cout << "The codebook was loaded with " << mNumCollisions << " collisions\n"
        << "There were " << mNodesWithTenCollisions << " indices with at least ten collisions\n"
        << "The highest number of collisions at one index is " << mMaxCollisionsAtOneIndex << endl;
}

string Codebook::encode(const string &word)
{
    int index;
    string output;

    index = hash(word);

    if(mHashTable[index] == NULL || mHashTable[index]->isEmpty())
    {
        output = word;
    }
    else
    {
        output = mHashTable[index]->getCode(word);
    }

    return output;
}

int Codebook::findSize(const string &fileName)
{
    int numPairs = 0;
    ifstream inFile;
    string line;

    inFile.open(fileName);
    if(inFile.is_open())
    {
        while(getline(inFile, line))
        {
            numPairs++;
        }
        inFile.close();
    }
    return numPairs;
}

int Codebook::hash(const string &word)
{
    int hashValue, length, firstLetter = 0, secondLetter = 0, thirdLetter = 0;

    length = word.length();
    if (length > 0)
        firstLetter = word[0] % 26;
    if (length > 1)
        secondLetter = word[1] % 26;
    if (length > 2)
        thirdLetter = word[2] % 26;
    hashValue = length + length * firstLetter + length * firstLetter * secondLetter + length * firstLetter * secondLetter * thirdLetter;

    return hashValue;
}

void Codebook::insert(const string &word, const string &code)
{
    int index, numNodes;
    CodePair pair(word, code);

    index = hash(word);
    mHashTable[index]->enqueue(pair);

    // Update collision metrics
    numNodes = mHashTable[index]->getCount();
    if (numNodes > 1)
        mNumCollisions++;
    if (numNodes == 10)
        mNodesWithTenCollisions++;
    if (numNodes > mMaxCollisionsAtOneIndex)
        mMaxCollisionsAtOneIndex = numNodes;
}

void Codebook::loadFile(const string &fileName)
{
    string word, code;
    ifstream file(fileName);
    while (!file.eof())
    {
        file >> word;
        file >> code;

        insert(word, code);
    }
}