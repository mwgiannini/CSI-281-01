/* ***       Author:  Wei Kian Chen
     *     Modified:  MW Giannini
     *  Last Update:  April 10, 2022
     *        Class:  CSI-281
     *     Filename:  bst.h
     *
     *  Description:
     *      This is the template binary search tree definition.
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my work.
     **********************************************************/


#ifndef _BST_H
#define _BST_H

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

template <typename T>
class BST
{
private:
    template <typename R>
    struct Node
    {
        R       mData;
        Node<R> *mLeft, *mRight;

        /*      Pre:  None
         *     Post:  This object is initialized using default
         *            values
         *  Purpose:  To initialize date object
         *****************************************************/
        Node()
        {
            mData = R();
            mLeft = NULL;
            mRight = NULL;
        }

        /*      Pre:  None
         *     Post:  This object is initialized using specified
         *            data
         *  Purpose:  To initialize date object
         *****************************************************/
        Node(R data)
        {
            mData = data;
            mLeft = NULL;
            mRight = NULL;
        }

        /*      Pre:  None
         *     Post:  This object is initialized using specified
         *            data with the specified children attached
         *  Purpose:  To initialize date object
         *****************************************************/
        Node(R data, Node<R> *left, Node<R> *right)
        {
            mData = data;
            mLeft = left;
            mRight = right;
        }
    };

    Node<T> *mRootNode;

    BST(T data, Node<T> *left, Node<T> *right);

    bool bfs(T searchKey, vector<T> &path, vector<Node<T> *> &toBeSearched);
    void destroySubtree(Node<T> *&node);
    bool dfs(T searchKey, Node<T> *node, vector<T> &path);
    void displayInOrder(Node<T> *node);
    void displayPreOrder(Node<T> *node);
    void displayPostOrder(Node<T> *node);
    void displayTree(Node<T> *node, int tab);
    int getHeight(Node<T> *node);
    void insert(Node<T> *&node, const T &data);
    int leavesCount(Node<T> *node);
    void makeDeletion(Node<T> *&node);
    int nodesCount(Node<T> *node);
    void remove(Node<T> *&node, const T &searchKey);

public:
    BST();
    ~BST();

    bool bfs(T searchKey);
    void clear();
    bool dfs(T searchKey);
    int  getHeight();
    void insert(T data);
    bool isEmpty();
    bool isExists(T searchKey);
    int  leavesCount();
    int  nodesCount();
    void remove(T searchKey);
    void printPath(T searchKey);
    void showInOrder();
    void showPreOrder();
    void showPostOrder();
    void showTree();
};


/*      Pre:  None
 *     Post:  The root node of the BST is initialized to NULL
 *  Purpose:  Default constructor
 **************************************************************/
template <typename T>
BST<T>::BST()
{
    mRootNode = NULL;
}


/*      Pre:  data, left pointer and right pointer
 *     Post:  The root node of the BST is initialized to the
 *            new root node with both left and right child
 *  Purpose:  Constructor
 **************************************************************/
template <typename T>
BST<T>::BST(T data, Node<T> *left, Node<T> *right)
{
    Node<T> *newNode;

    newNode = new Node<T>(data, left, right);
    if (newNode != NULL)
        mRootNode = newNode;
}


/*      Pre:  The BST is instantiated
 *     Post:  The root node of the BST is initialized to NULL
 *  Purpose:  Default constructor
 **************************************************************/
template <typename T>
BST<T>::~BST()
{
    destroySubtree(mRootNode);

    mRootNode = NULL;
}


/*      Pre:  A search key
 *     Post:  True is return is the search key is found in the
 *            BST, otherwise false
 *  Purpose:  Searching the tree using breadth-first search
 **************************************************************/
template <typename T>
bool BST<T>::bfs(T searchKey)
{
    vector<Node<T> *> toBeSearched;
    vector<T> path;
    toBeSearched.push_back(mRootNode);
    bool found = bfs(searchKey, path, toBeSearched);
    if (found)
        for (T item : path)
            cout << item;
    else
        cout << "The search key does not exist in the tree.";

    cout << endl;
    return found;
}

/*      Pre:  A search key, a vector to store the path,
 *            and a vector to keep track of the next nodes to search
 *     Post:  True is returned if the search key is found in the
 *            BST, otherwise false
 *            The vector contains the path to the the found
 *            node if one exists
 *  Purpose:  Searching the tree using breadth-first search
 **************************************************************/
template <typename T>
bool BST<T>::bfs(T searchKey, vector<T> &path, vector<Node<T> *> &toBeSearched)
{
    Node<T> *node = toBeSearched.front();
    toBeSearched.erase(toBeSearched.begin());
    if (node == NULL)
        return false;
    if (node->mData != searchKey)
    {
        toBeSearched.push_back(node->mLeft);
        toBeSearched.push_back(node->mRight);
    }
    if (node->mData == searchKey ||
        bfs(searchKey, path, toBeSearched) ||
        bfs(searchKey, path, toBeSearched))
    {
        path.insert(path.begin(), node->mData);
        return true;
    }
    
}


/*      Pre:  The BST is instantiated
 *     Post:  The entire BST is deleted
 *  Purpose:  To clear the entire BST
 **************************************************************/
template <typename T>
void BST<T>::clear()
{
    destroySubtree(mRootNode);

    mRootNode = NULL;
}


/*      Pre:  A node within the BST
 *     Post:  All the subtree branching from the node (including
 *            the node) is deleted
 *  Purpose:  To delete a subtree
 **************************************************************/
template <typename T>
void BST<T>::destroySubtree(Node<T> *&node)
{
    if (node == NULL)
        return;

    // go to the leave node and delete from there
    destroySubtree(node->mLeft);
    destroySubtree(node->mRight);

    // delete the node
    delete node;

    node = NULL;
}


/*      Pre:  A search key
 *     Post:  True is return is the search key is found in the
 *            BST, otherwise false
 *  Purpose:  Searching the tree using depth-first search
 **************************************************************/
template <typename T>
bool BST<T>::dfs(T searchKey)
{
    vector<T> path;
    bool found = dfs(searchKey, mRootNode, path);
    if (found)
        for (T item : path)
            cout << item;
    else
        cout << "The search key does not exist in the tree.";
        
    cout << endl;
    return found;
}

/*      Pre:  A search key, root node, and vector to store the path
 *     Post:  True is returned if the search key is found in the
 *            subtree, otherwise false
 *            The vector contains the path to the the found
 *            node if one exists
 *  Purpose:  Searching the subtree using depth-first search
 **************************************************************/
template <typename T>
bool BST<T>::dfs(T searchKey, Node<T> *node, vector<T> &path)
{
    if (node == NULL)
        return false;
    if (node->mData == searchKey ||
        dfs(searchKey, node->mLeft, path) ||
        dfs(searchKey, node->mRight, path))
    {
        path.insert(path.begin(), node->mData);
        return true;
    }
}


/*      Pre:  A node within a tree
 *     Post:  The entire BST is displayed using in-order format
 *  Purpose:  A private function that display the entire BST
 *            using in-order format.
 **************************************************************/
template <typename T>
void BST<T>::displayInOrder(Node<T> *node)
{
    if (node == NULL)
        return;
    if (node->mLeft != NULL)
        displayInOrder(node->mLeft);
    cout << node->mData;
    if (node->mRight != NULL)
        displayInOrder(node->mRight);
}


/*      Pre:  A node within a tree
 *     Post:  The entire BST is displayed using pre-order format
 *  Purpose:  A private function that display the entire BST
 *            using pre-order format.
 **************************************************************/
template <typename T>
void BST<T>::displayPreOrder(Node<T> *node)
{
    if (node == NULL)
        return;
    cout << node->mData;
    if (node->mLeft != NULL)
        displayPreOrder(node->mLeft);
    if (node->mRight != NULL)
        displayPreOrder(node->mRight);
}


/*      Pre:  A node within a tree
 *     Post:  The entire BST is displayed using post-order format
 *  Purpose:  A private function that display the entire BST
 *            using post-order format.
 **************************************************************/
template <typename T>
void BST<T>::displayPostOrder(Node<T> *node)
{
    if (node == NULL)
        return;
    if (node->mLeft != NULL)
        displayPostOrder(node->mLeft);
    if (node->mRight != NULL)
        displayPostOrder(node->mRight);
    cout << node->mData;
}


/*      Pre:  A node within a tree
 *     Post:  The entire BST is displayed
 *  Purpose:  A private function that display the entire BST
 **************************************************************/
template <typename T>
void BST<T>::displayTree(Node<T> *node, int tab)
{
    if (node == NULL)
        return;

    for (int i = 0; i < tab; i++)
        cout << "  ";
    cout << node->mData << endl;

    if (node->mLeft != NULL)
        displayTree(node->mLeft, tab+1);
    if (node->mRight != NULL)
        displayTree(node->mRight, tab+1);
}


/*      Pre:  None
 *     Post:  The height of a tree is returned
 *  Purpose:  To compute the longest branch within the BST
 **************************************************************/
template <typename T>
int BST<T>::getHeight()
{
    return getHeight(mRootNode);
}

/*      Pre:  A node within the BST
 *     Post:  The height of the subtree is returned
 *  Purpose:  To compute the height of a subtree within the BST
 **************************************************************/
template <typename T>
int BST<T>::getHeight(Node<T> *node)
{
    if (node == NULL)
        return 0;

    int height;
    int leftBranchHeight;
    int rightBranchHeight;

    if (node->mLeft == NULL)
        leftBranchHeight = -1;
    else
        leftBranchHeight = getHeight(node->mLeft);
    
    if (node->mRight == NULL)
        rightBranchHeight = -1;
    else
        rightBranchHeight = getHeight(node->mRight);

    height = leftBranchHeight > rightBranchHeight ? leftBranchHeight + 1 : rightBranchHeight + 1;

    return height;
}


/*      Pre:  A data to insert into a BST
 *     Post:  A new data is inserted into a BST
 *  Purpose:  To insert a new value into a BST
 **************************************************************/
template <typename T>
void BST<T>::insert(T data)
{
    insert(mRootNode, data);
}


/*      Pre:  A node within a tree and the value to insert
 *     Post:  The new value is inserted into the BST
 *  Purpose:  A private function that insert a new data into a
 *            BST.  BST does not allow duplication of value.
 *            Hence, a duplicated value will not be inserted
 **************************************************************/
template <typename T>
void BST<T>::insert(Node<T> *&node, const T &data)
{
    if (node == NULL)
    {
        node = new Node<T>(data);
        return;
    }

    if (node->mData == data)
        return;
    else if (node->mData < data)
        insert(node->mRight, data);
    else
        insert(node->mLeft, data);
}


/*      Pre:  None
 *     Post:  True if the BST is empty, otherwise false
 *  Purpose:  To determine if the BST is empty
 **************************************************************/
template <typename T>
bool BST<T>::isEmpty()
{
    return (mRootNode == NULL);
}


/*      Pre:  A search key
 *     Post:  True is return if the search key existed in the
 *            BST, otherwise false
 *  Purpose:  To search if a search key exists in the BST using
 *            the typical binary tree search
 **************************************************************/
template <typename T>
bool BST<T>::isExists(T searchKey)
{
    Node<T> *tmp;
    bool found = false;

    tmp = mRootNode;
    while (tmp != NULL && !found)
    {
        if (tmp->mData == searchKey)
            found = true;
        else if (tmp->mData > searchKey)
            tmp = tmp->mLeft;
        else
            tmp = tmp->mRight;
    }

    return found;
}


/*      Pre:  None
 *     Post:  The number of leave nodes is returned
 *  Purpose:  To determine the number of leave nodes in the BST
 **************************************************************/
template <typename T>
int BST<T>::leavesCount()
{
    return leavesCount(mRootNode);
}

/*      Pre:  A node within the BST
 *     Post:  The number of leaf nodes in the subtree is returned
 *  Purpose:  To determine the number of leave nodes of a subtree
 **************************************************************/
template <typename T>
int BST<T>::leavesCount(Node<T> *node)
{
    if (node == NULL)
        return 0;

    int count = 0;

    if (node->mLeft != NULL)
        count += leavesCount(node->mLeft);
    if (node->mRight != NULL)
        count += leavesCount(node->mRight);
    if (node->mLeft == NULL && node->mRight == NULL)
        count++;
    return count;
}


/*      Pre:  A node within the BST
 *     Post:  The node is deleted from the BST
 *  Purpose:  A private function that delete the node from the
 *            BST.  If the node has only one child, then the
 *            child will serve as the new root node for that
 *            branch.  However, if the node has two children,
 *            then the right child will serve as the new root
 *            node for the branch.
 **************************************************************/
template <typename T>
void BST<T>::makeDeletion(Node<T> *&node)
{
    Node<T> *toBeDeleted, *attachPoint;

    toBeDeleted = node;

    if (node->mRight == NULL)
    {
        node = node->mLeft;
    }
    else if (node->mLeft == NULL)
    {
        node = node->mRight;
    }
    else
    {
        attachPoint = node->mRight;

        while (attachPoint->mLeft != NULL)
            attachPoint = attachPoint->mLeft;

        attachPoint->mLeft = node->mLeft;

        node = node->mRight;
    }

    // actually deleting the node
    delete toBeDeleted;
}


/*      Pre:  None
 *     Post:  The number of nodes is returned
 *  Purpose:  To determine the number of nodes in the BST
 **************************************************************/
template <typename T>
int BST<T>::nodesCount()
{
    return nodesCount(mRootNode);
}

/*      Pre:  A node within the BST
 *     Post:  The number of ancestor nodes is returned
 *  Purpose:  A private function to determine the number of ancestors of a given node.
 **************************************************************/
template <typename T>
int BST<T>::nodesCount(Node<T> *node)
{
    if (node == NULL)
        return 0;

    int count = 1;

    if (node->mLeft != NULL)
        count += nodesCount(node->mLeft);
    if (node->mRight != NULL)
        count += nodesCount(node->mRight);

    return count;
}


/*      Pre:  None
 *     Post:  The path from the root node to the search key is
 *            displayed on the screen or an error message
 *            indicating the search key does not exist
 *  Purpose:  To display the path from the root node to the
 *            search key is displayed on the screen.  If the
 *            search key does not exist in the BST, a message
 *            indicating the search key does not exist in the
 *            BST
 **************************************************************/
template <typename T>
void BST<T>::printPath(T searchKey)
{
    bool found = false;
    Node<T> *tmp = mRootNode;
    stringstream path;

    while (!found)
    {
        if (tmp == NULL)
            break;

        path << tmp->mData;

        if (searchKey < tmp->mData)
            tmp = tmp->mLeft;
        else if (searchKey > tmp->mData)
            tmp = tmp->mRight;
        else
            found = true;
    }

    if (found)
        cout << path.str() << endl;
    else
        cout << "The search key does not exist in the tree." << endl;
}


/*      Pre:  A search key
 *     Post:  The search key is removed from the BST
 *  Purpose:  To remove a value from a BST
 **************************************************************/
template <typename T>
void BST<T>::remove(T searchKey)
{
    remove(mRootNode, searchKey);
}


/*      Pre:  A node within the BST and a search key
 *     Post:  The search key is removed from the BST if the
 *            value exists
 *  Purpose:  A private function that to remove a value from a
 *            BST recursively.  This function will find the node
 *            where the value occur.  Once the node is found,
 *            call makeDeletion to complete the process.
 **************************************************************/
template <typename T>
void BST<T>::remove(Node<T> *&node, const T &searchKey)
{
    if (node == NULL)
        return;

    if (node->mData > searchKey)
        remove(node->mLeft, searchKey);
    else if (node->mData < searchKey)
        remove(node->mRight, searchKey);
    else
        makeDeletion(node);
}


/*      Pre:  None
 *     Post:  The entire BST is displayed using in-order format
 *  Purpose:  A function that display the entire BST using
 *            in-order format.  This function will call
 *            displayInOrder to complete the process
 **************************************************************/
template <typename T>
void BST<T>::showInOrder()
{
    displayInOrder(mRootNode);
    cout << endl;
}


/*      Pre:  None
 *     Post:  The entire BST is displayed using pre-order format
 *  Purpose:  A function that display the entire BST using
 *            pre-order format.  This function will call
 *            displayPreOrder to complete the process
 **************************************************************/
template <typename T>
void BST<T>::showPreOrder()
{
    displayPreOrder(mRootNode);
    cout << endl;
}


/*      Pre:  None
 *     Post:  The entire BST is displayed using post-order format
 *  Purpose:  A function that display the entire BST using
 *            post-order format.  This function will call
 *            displayPostOrder to complete the process
 **************************************************************/
template <typename T>
void BST<T>::showPostOrder()
{
    displayPostOrder(mRootNode);
    cout << endl;
}


/*      Pre:  None
 *     Post:  The entire BST is displayed
 *  Purpose:  A function that display the entire BST.  This
 *            function will call displayTree to complete the
 *            process
 **************************************************************/

template <typename T>
void BST<T>::showTree()
{
    displayTree(mRootNode, 0);
}

#endif