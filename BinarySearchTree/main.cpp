// ---------------------------------------------------------------------------
// Name: Devin Kennedy
// Course-Section: CS355-01
// Assignment: Assignment #8
// Date due: 11/09/2025
// Description:
// ---------------------------------------------------------------------------
#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int main()
{
    bSearchTreeType<int> bst;

    int temp;

    for(int i = 0; i < 5; i++)
    {
        cin >> temp;
        bst.insert(temp);
    }

    cout << "In-Order Traversal" << endl;
    bst.inorderTraversal();
    cout << endl << "Pre-Order Traversal" << endl;
    bst.preorderTraversal();
    cout << endl << "Post-Order Traveral" << endl;
    bst.postorderTraversal();

    cout << endl << "Minimum value in BST: " << bst.minVal();
    cout << endl << "Maximum value in BST: " << bst.maxVal() << endl;

    return 0;
}
