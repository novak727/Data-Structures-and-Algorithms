// -----------------------------------------------------------------------------
// Name: Devin Kennedy
// Course-Section: CS355-01
// Assignment: Project #7
// Date due: 11/25/2025
// Description: Templated AVLTree implementation with support for inserting
// items, doing inorder, preorder, and postorder traversals, and copying trees.
// -----------------------------------------------------------------------------
#include <iostream>

#include "AVLType.h"

using namespace std;

int main()
{
    AVLType<int> tree;

    tree.insert(35);
    tree.insert(45);
    tree.insert(10);
    tree.insert(7);
    tree.insert(72);
    tree.insert(96);
    tree.insert(32);
    tree.insert(24);

    cout << "Inorder traversal:" << endl;
    tree.inorder();

    cout << "Preorder traversal:" << endl;
    tree.preorder();

    cout << "Postorder traversal:" << endl;
    tree.postorder();

    cout << "Copying tree to tree2" << endl;
    AVLType<int> tree2;
    tree2 = tree;

    cout << "tree2 Inorder traversal:" << endl;
    tree2.inorder();

    cout << "tree2 Preorder traversal:" << endl;
    tree2.preorder();

    cout << "tree2 Postorder traversal:" << endl;
    tree2.postorder();

    return 0;
}
