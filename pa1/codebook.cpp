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
#include <fstream>
#include <string>
#include "codebook.h"

Codebook::Codebook(const std::string &fileName)
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    this->loadFile(fileName);
}

Codebook::~Codebook()
{
    Node *current = head;
    Node *next = head->next;

    while (next != nullptr)
    {
        delete current;
        current = next;
        next = current->next;
    }
}

void Codebook::loadFile(const std::string &fileName)
{
    std::ifstream file(fileName);
    while (!file.eof())
    {
        // Construct the next node
        Node *newNode = new Node();
        file >> newNode->word;
        file >> newNode->code;

        // Add the node to the list
        *this += newNode;
    }
}

void Codebook::addNode(Node *newNode)
{
    newNode->next = nullptr;

    if (head == nullptr)
        this->head = newNode;
    else
        this->tail->next = newNode;

    this->tail = newNode;
    this->size++;
}

void Codebook::operator+=(Node *newNode)
{
    this->addNode(newNode);
}

std::string Codebook::retrieveCodeFor(const std::string &word) const
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->word == word)
            return current->code;
        current = current->next;
    }
    return word;
}