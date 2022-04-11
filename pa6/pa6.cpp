/**
 * @ Author: MW Giannini
 * @ Due: 4/11/2022
 * @ Course: CSI-281-01
 * @ Assignment: PA6
 * @ Certificate of Authenticity: I certify that this is entirely my own work, except where I have given
 * @ : fully-documented references to the work of others. I understand the definition and
 * @ ~: consequences of plagiarism and acknowledge that the assessor of this assignment
 * @ ~~: may, for the purpose of assessing this assignment:
 * @ ~~~: - Reproduce this assignment and provide a copy to another member of academic staff;
 * @ ~~~~: and/or
 * @ ~~~~~: - Communicate a copy of this assignment to a plagiarism checking service (which may
 * @ ~~~~~~: then retain a copy of this assignment on its database for the purpose of future
 * @ ~~~~~~~: plagiarism checking)
 * @ Description: Stub driver for BST.
 */


#include <iostream>
#include "bst.h"

using namespace std;

template <typename T>
void printTest(BST<T> tree)
{
	cout << "Nodes: " << tree.nodesCount() << '\n'
		<< "Leaf nodes: " << tree.leavesCount() << '\n'
		<< "Height: " << tree.getHeight() << '\n';
	cout << "Path: ";
	tree.printPath(5);
	cout << "Display:" << endl;
	tree.showTree();
	cout << "Inorder: ";
	tree.showInOrder();
	cout << "Preorder: ";
	tree.showPreOrder();
	cout << "Postorder: ";
	tree.showPostOrder();
	cout << "DFS: ";
	tree.dfs(4);
	cout << "BFS: ";
	tree.bfs(4);
}

int main()
{
	BST<int> tree, nullTree;
	int list[] = {5, 3, 8, 1, 4};

	for(int num : list)
		tree.insert(num);

	cout << "POPULATED TREE" << endl;
	printTest(tree);

	cout << "\nNULL TREE" << endl;
	printTest(nullTree);

	return 0;
}