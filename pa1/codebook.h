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

#pragma once
#include <string>
// A linked list class for storing codebooks

class Codebook
{
public:
    /*      Pre:  Given file exists with the proper codebook format
     *     Post:  A linked list is created with nodes containing the word-code pairs from the given file
     *  Purpose:  Construct a Codebook object
     *********************************************************/
    Codebook(const std::string& fileName);


    /*      Pre:  None
     *     Post:  Linked list memory deallocated
     *  Purpose:  Destroy a Codebook object
     *********************************************************/
    ~Codebook();

    /*      Pre:  None
     *     Post:  Returns the corresponding code for the given word or the word itself if it is not in the list
     *  Purpose:  Retrieve the corresponding code for a given word
     *********************************************************/
    std::string retrieveCodeFor(const std::string& word) const;

private:
    struct Node
    {
        std::string word;
        std::string code;
        Node *next;
    };

    /*      Pre:  Given file exists with the proper codebook format
     *     Post:  Contents of the file are added to the end of the linked list
     *  Purpose:  Load the codebook file into memory
     *********************************************************/
    void loadFile(const std::string& fileName);

    /*      Pre:  None
     *     Post:  The given Node is appended to the linked list
     *  Purpose:  Add a Node to the linked list
     *********************************************************/
    void addNode(Node* newNode);

    // Wraps addNode
    void operator+=(Node* newNode);

    Node *head;
    Node *tail;
    int size;
};