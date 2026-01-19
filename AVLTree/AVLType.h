#ifndef AVLTYPE_H
#define AVLTYPE_H

#include <iostream>
using namespace std;

//------------------------------------------------------------------------------
/* AVLNode
*  A struct for each node in an AVL Tree.
*/
template <class elemType>
struct AVLNode
{
    elemType info;
    int bfactor;
    AVLNode<elemType> *lLink;
    AVLNode<elemType> *rLink;
};

//------------------------------------------------------------------------------
/* AVLType
* A templated class for an AVLTree implementation with the AVLNode struct.
* One private attribute: The root, a pointer to an AVLNode<elemType>.
* Methods are available to handle inserting into the AVL Tree and all
* appropriate rotations, inorder, preorder, and postorder traversals, a default
* constructor, copy constructor, and destructor, and helper functions as needed
* for each task. The assignment operator was also overloaded.
*/
template <class elemType>
class AVLType
{
    public:
        //----------------------------------------------------------------------
        /* Default constructor.
        */
        AVLType()
        {
            root = nullptr;
        }

        //----------------------------------------------------------------------
        /* Copy constructor.
        */
        AVLType(AVLType<elemType>& otherTree)
        {
            root = copyTree(otherTree.root);
        }

        //----------------------------------------------------------------------
        /* Destructor.
        */
        ~AVLType()
        {
            destroyHelper(root);
        }

        //----------------------------------------------------------------------
        /* Overloaded assignment operator
        */
        AVLType<elemType>& operator=(const AVLType<elemType>& otherTree)
        {
            if (this != &otherTree)
            {
                destroyHelper(root);
                root = copyTree(otherTree.root);
            }

            return *this;
        }

        //----------------------------------------------------------------------
        /* insert() creates a new AVLNode, then calls a helper function to
        *  insert the node into the proper place in the AVL Tree.
        */
        void insert(const elemType& newItem)
        {
            bool isTaller = false;
            AVLNode<elemType> *newNode;

            newNode = new AVLNode<elemType>;
            newNode->info = newItem;
            newNode->bfactor = 0;
            newNode->lLink = nullptr;
            newNode->rLink = nullptr;

            insertIntoAVL(root, newNode, isTaller);
        }

        //----------------------------------------------------------------------
        /* inorder() calls the helper function to perform an inorder traversal.
        */
        void inorder() const
        {
            inorderHelper(root);
            cout << endl;
        }

        //----------------------------------------------------------------------
        /* preorder() calls the helper function to perform a preorder traversal.
        */
        void preorder() const
        {
            preorderHelper(root);
            cout << endl;
        }

        //----------------------------------------------------------------------
        /* postorder() calls the helper function to perform a postorder
        *  traversal.
        */
        void postorder() const
        {
            postorderHelper(root);
            cout << endl;
        }
    private:
        AVLNode<elemType>* root;

        //----------------------------------------------------------------------
        /* inorderHelper() recursively traverses through the AVL Tree to
        *  perform an inorder traversal.
        */
        void inorderHelper(AVLNode<elemType>* node) const
        {
            if (node != nullptr)
            {
                inorderHelper(node->lLink);
                cout << node->info << " ";
                inorderHelper(node->rLink);
            }
        }

        //----------------------------------------------------------------------
        /* preorderHelper() recursively traverses through the AVL Tree to
        *  perform a preorder traversal.
        */
        void preorderHelper(AVLNode<elemType>* node) const
        {
            if (node != nullptr)
            {
                cout << node->info << " ";
                preorderHelper(node->lLink);
                preorderHelper(node->rLink);
            }
        }

        //----------------------------------------------------------------------
        /* postorderHelper() recursively traverses through the AVL Tree to
        *  perform a postorder traversal.
        */
        void postorderHelper(AVLNode<elemType>* node) const
        {
            if (node != nullptr)
            {
                postorderHelper(node->lLink);
                postorderHelper(node->rLink);
                cout << node->info << " ";
            }
        }

        //----------------------------------------------------------------------
        /* copyTree() is a helper function that recursively copies each node of
        *  an AVL Tree, ultimately rebuilding the original AVL Tree as a deep
        *  copy.
        */
        AVLNode<elemType>* copyTree(AVLNode<elemType>* node)
        {
            if (node == nullptr)
            {
                return nullptr;
            }
            else
            {
                AVLNode<elemType>* newNode = new AVLNode<elemType>;
                newNode->info = node->info;
                newNode->bfactor = node->bfactor;
                newNode->lLink = copyTree(node->lLink);
                newNode->rLink = copyTree(node->rLink);
                return newNode;
            }
        }

        //----------------------------------------------------------------------
        /* insertIntoAVL() recursively traverses through the AVL Tree until it
        *  finds the appropriate location for the new AVLNode to be placed, then
        *  calls the functions to rebalance the AVL Tree.
        */
        void insertIntoAVL(AVLNode<elemType>* &root, AVLNode<elemType> *newNode,
                           bool& isTaller)
        {
            if (root == nullptr)
            {
                root = newNode;
                isTaller = true;
            }
            else if (root->info == newNode->info)
            {
                cout << "No duplicates are allowed." << endl;
            }
            else if (root->info > newNode->info)
            {
                insertIntoAVL(root->lLink, newNode, isTaller);

                if (isTaller)
                {
                    switch (root->bfactor)
                    {
                    case -1:
                        balanceFromLeft(root);
                        isTaller = false;
                        break;
                    case 0:
                        root->bfactor = -1;
                        isTaller = true;
                        break;
                    case 1:
                        root->bfactor = 0;
                        isTaller = false;
                    }
                }
            }
            else
            {
                insertIntoAVL(root->rLink, newNode, isTaller);

                if (isTaller)
                {
                    switch (root->bfactor)
                    {
                    case -1:
                        root->bfactor = 0;
                        isTaller = false;
                        break;
                    case 0:
                        root->bfactor = 1;
                        isTaller = true;
                        break;
                    case 1:
                        balanceFromRight(root);
                        isTaller = false;
                    }
                }
            }
        }

        //----------------------------------------------------------------------
        /* rotateToLeft() implements the left rotation of a node in the AVL
        *  tree.
        */
        void rotateToLeft(AVLNode<elemType>* &root)
        {
            AVLNode<elemType> *p;

            if (root == nullptr)
            {
                cout << "Error in the tree" << endl;
            }
            else if (root->rLink == nullptr)
            {
                cout << "Error in the tree: No right subtree to rotate." << endl;
            }
            else
            {
                p = root->rLink;
                root->rLink = p->lLink;

                p->lLink = root;
                root = p;
            }
        }

        //----------------------------------------------------------------------
        /* rotateToRight() implements the right rotations of a node in an AVL
        *  tree.
        */
        void rotateToRight(AVLNode<elemType>* &root)
        {
            AVLNode<elemType> *p;

            if (root == nullptr)
            {
                cout << "Error in the tree" << endl;
            }
            else if(root->lLink == nullptr)
            {
                cout << "Error in the tree: No left subtree to rotate." << endl;
            }
            else
            {
                p = root->lLink;
                root->lLink = p->rLink;

                p->rLink = root;
                root = p;
            }
        }

        //----------------------------------------------------------------------
        /* balanceFromLeft() rebalances the subtree when it is left double high.
        */
        void balanceFromLeft(AVLNode<elemType>* &root)
        {
            AVLNode<elemType> *p;
            AVLNode<elemType> *w;

            p = root->lLink;

            switch (p->bfactor)
            {
            case -1:
                root->bfactor = 0;
                p->bfactor = 0;
                rotateToRight(root);
                break;
            case 0:
                cout << "Error: Cannot balance from the left." << endl;
                break;
            case 1:
                w = p->rLink;
                switch (w->bfactor)
                {
                case -1:
                    root->bfactor = 1;
                    p->bfactor = 0;
                    break;
                case 0:
                    root->bfactor = 0;
                    p->bfactor = 0;
                    break;
                case 1:
                    root->bfactor = 0;
                    p->bfactor = -1;
                }

                w->bfactor = 0;
                rotateToLeft(p);
                root->lLink = p;
                rotateToRight(root);
            }
        }

        //----------------------------------------------------------------------
        /* balanceFromRight() rebalances the subtree when it is right double
        *  high.
        */
        void balanceFromRight(AVLNode<elemType>* &root)
        {
            AVLNode<elemType> *p;
            AVLNode<elemType> *w;

            p = root->rLink;

            switch (p->bfactor)
            {
            case -1:
                w = p->lLink;
                switch (w->bfactor)
                {
                case -1:
                    root->bfactor = 0;
                    p->bfactor = 1;
                    break;
                case 0:
                    root->bfactor = 0;
                    p->bfactor = 0;
                    break;
                case 1:
                    root->bfactor = -1;
                    p->bfactor = 0;
                }

                w->bfactor = 0;
                rotateToRight(p);
                root->rLink = p;
                rotateToLeft(root);
                break;
            case 0:
                cout << "Error: Cannot balance from the left." << endl;
                break;
            case 1:
                root->bfactor = 0;
                p->bfactor = 0;
                rotateToLeft(root);
            }
        }

        //----------------------------------------------------------------------
        /* destroyHelper() is a helper function that recursively deletes each
        *  node in the AVL tree
        */
        void destroyHelper(AVLNode<elemType>* &node)
        {
            if (node != nullptr)
            {
                destroyHelper(node->lLink);
                destroyHelper(node->rLink);
                delete node;
                node = nullptr;
            }
        }
};

#endif // AVLTYPE_H
