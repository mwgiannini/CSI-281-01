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

#ifndef CODEBOOK_H
#define CODEBOOK_H

#include <string>
#include "queue.h"
#include "codepair.h"

using namespace std;

class Codebook
{
public:
    /*      Pre:  Given file exists with the proper codebook format
     *     Post:  Codebook loaded into two arrays.
     *  Purpose:  Construct a Codebook object
     *********************************************************/
    Codebook(const string &fileName);

    /*      Pre:  None
     *     Post:  Linked list memory deallocated
     *  Purpose:  Destroy a Codebook object
     *********************************************************/
    ~Codebook();

    /*      Pre:  None
     *     Post:  Returns the corresponding code for the given word
     *  Purpose:  Retrieve the corresponding code for a given word
     *********************************************************/
    string encode(const string &word);

    /*      Pre:  None
     *     Post:  Displays the collision metrics to cout
     *  Purpose:  Display the collision metrics
     *********************************************************/
    void displayCollisionMetrics();

private: 
    CollisionQueue **mHashTable;
    int mNumCollisions, mNodesWithTenCollisions,
        mMaxCollisionsAtOneIndex, mNumPairs;

    /*      Pre:  Given filename
     *     Post:  Returns the number of entries in the file
     *  Purpose:  Find the number of entries in the file
     *********************************************************/
    int findSize(const string &fileName);

    /*      Pre:  None
     *     Post:  Returns the index for the hash table
     *  Purpose:  Hash the given code word
     *********************************************************/
    int hash(const string &word);

    /*      Pre:  Given word and code
     *     Post:  Inserts the given word and code into the codebook
     *  Purpose:  Add a code pair to the codebook
     *********************************************************/
    void insert(const string &word, const string &code);

    /*      Pre:  Given filename
     *     Post:  Contents of the file are loaded into the hash table
     *  Purpose:  Load the codebook file into the hash table
     *********************************************************/
    void loadFile(const string &fileName);
};

#endif