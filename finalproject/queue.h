/* ***       Author:  Wei Kian Chen with students in CSI-281
     *     Modified:  MW Giannini
     *  Last Update:  October 25, 2021
     *        Class:  CSI-281
     *     Filename:  queue.h
     *
     *  Description:
     *      This is the template queue definition.
     *  
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely own work.
     ******************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include "codepair.h"

using namespace std;

class CollisionQueue {
   struct Node
   {
      CodePair   mData;
      Node      *mNext;

      /*      Pre:  None
         *     Post:  This object is initialized using default values
         *  Purpose:  To initialize node object
         *************************************************************/
      Node()
      {
         mData = CodePair();
         mNext = NULL;
      }

      /*      Pre:  None
         *     Post:  This object is initialized using specified data
         *  Purpose:  To initialize node object
         *************************************************************/
      Node(CodePair data)
      {
         mData = data;
         mNext = NULL;
      }
   };

   private:
      Node *mFront, *mRear;
      int   mCount;

   public:
      CollisionQueue();
      ~CollisionQueue();

      int  getCount();

      void clear();
      void enqueue(CodePair data);
      bool isEmpty();
      string  getCode(const string &word);
};

#endif