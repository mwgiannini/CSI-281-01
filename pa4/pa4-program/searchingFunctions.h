/**
 * @ Author: MW Giannini
 * @ Create Time: 2022-03-02 21:15:56
 * @ Course: CSI-281-01
 * @ Assignment: PA4
 * @ Certificate of Authenticity: I certify that this is entirely my own work, except where I have given
 * @ : fully-documented references to the work of others. I understand the definition and
 * @ ~: consequences of plagiarism and acknowledge that the assessor of this assignment
 * @ ~~: may, for the purpose of assessing this assignment:
 * @ ~~~: - Reproduce this assignment and provide a copy to another member of academic staff;
 * @ ~~~~: and/or
 * @ ~~~~~: - Communicate a copy of this assignment to a plagiarism checking service (which may
 * @ ~~~~~~: then retain a copy of this assignment on its database for the purpose of future
 * @ ~~~~~~~: plagiarism checking)
 * @ Description: Searching function templates created for PA4
 */

#ifndef SEARCHINGFUNCTIONS_H
#define SEARCHINGFUNCTIONS_H

/* Search an unsorted array using sequential search

Pre: Provide unsorted array, search key, and size
Post: Return true if the array contains the search key
*/
template <typename T>
bool sequentialSearch(T list[], T searchKey, int size)
{
    int i;
    bool found = false;

    for (i = 0; i < size; i++)
    {
        if (list[i] == searchKey)
        {
            found = true;
            break;
        }
    }

    return found;
}

/* Search an sorted array using sequential search

Pre: Provide sorted array, search key, and size
Post: Return true if the array contains the search key
*/
template <typename T>
bool sortedSequentialSearch(T list[], T searchKey, int size)
{
    int i;
    bool found = false;

    for (i = 0; i < size; i++)
    {
        if (list[i] == searchKey)
        {
            found = true;
            break;
        }
        else if (list[i] > searchKey)
            break;
    }

    return found;
}

/* Search an sorted array using binary search

Pre: Provide sorted array, search key, upper bound, and lower bound
Post: Return true if the array contains the search key
*/
template <typename T>
bool binarySearch(T list[], T searchKey, int LB, int UB)
{
    int mid;
    bool found = false;

    if (LB <= UB)
    {
        mid = (LB + UB) / 2;

        if (list[mid] == searchKey)
            found = true;
        
        else if (list[mid] > searchKey)
            return binarySearch(list, searchKey, LB, mid - 1);
        
        else
            return binarySearch(list, searchKey, mid + 1, UB);
    }

    return found;
}

/* Search an sorted array using a non recursive implementation
of binary search

Pre: Provide sorted array, search key, upper bound, and lower bound
Post: Return true if the array contains the search key
*/
template <typename T>
bool nonRecursiveBinarySearch(T list[], T searchKey, int LB, int UB)
{
    int mid;
    bool found = false;

    while (LB <= UB)
    {
        mid = (LB + UB) / 2;

        if (list[mid] == searchKey)
        {
            found = true;
            break;
        }
        
        else if (list[mid] > searchKey)
            UB = mid - 1;
        
        else
            LB = mid + 1;
    }

    return found;
}

#endif