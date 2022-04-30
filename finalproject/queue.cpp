#include "queue.h"
#include <string>

using namespace std;

/*      Pre:  The queue is instantiated
 *     Post:  Both mFront and mRear are initialized to NULL and mCount
 *            is set to zero
 *  Purpose:  To initialize queue object
 *********************************************************************/
CollisionQueue::CollisionQueue()
{
    mFront = NULL;
    mRear = NULL;
    mCount = 0;
}


/*      Pre:  The queue is instantiated
 *     Post:  The queue is removed and both mFront and mRear are
 *            reset to NULL and mCount is reset to zero
 *  Purpose:  To clear up a queue object
 *********************************************************************/
CollisionQueue::~CollisionQueue()
{
    clear();
}


/*      Pre:  The queue is instantiated
 *     Post:  The count for the queue object is returned
 *  Purpose:  To retrieve the count for a queue object
 *********************************************************************/
int CollisionQueue::getCount()
{
    return mCount;
}


/*      Pre:  The queue is instantiated
 *     Post:  The entire queue is cleared
 *  Purpose:  To clear the entire queue object
 *********************************************************************/
void CollisionQueue::clear()
{
    Node *tmp;

    while (mFront != NULL)
    {
        tmp = mFront;
        mFront = mFront->mNext;
        tmp->mNext = NULL;
        delete tmp;
    }

    mRear = NULL;
    mCount = 0;
}


/*      Pre:  The queue is instantiated
 *     Post:  A new node is added at the end of the queue
 *  Purpose:  To add a new data to the queue
 *********************************************************************/
void CollisionQueue::enqueue(CodePair data)
{
    Node *newNode;

    newNode = new Node(data);
    if (newNode == NULL)
        return;

    if (mCount == 0)
    {
        mFront = newNode;
        mRear = newNode;
    }
    else
    {
        mRear->mNext = newNode;
        mRear = newNode;
    }

    mCount++;
}


/*      Pre:  The queue is instantiated
 *     Post:  True if the queue is empty, otherwise false
 *  Purpose:  To determine if the queue is empty
 *********************************************************************/
bool CollisionQueue::isEmpty()
{
    return mCount == 0;
}


/*      Pre:  The queue is instantiated and a searchKey is available
 *     Post:  Returns the code for the word if found, otherwise
 *            returns empty string
 *  Purpose:  To search for the code of a word in the queue
 *********************************************************************/
string CollisionQueue::getCode(const string &word)
{
    Node *tmp;
    string code = word;

    tmp = mFront;
    while (tmp != NULL && code == word)
    {
        if (tmp->mData.mWord == word)
            code = tmp->mData.mCode;
        else
            tmp = tmp->mNext;
    }

    return code;
}