#ifndef H_binarySearchTree
#define H_binarySearchTree

#include <iostream>

using namespace std;

// Definition of the Node
template <class elemType>
struct nodeType
{
    elemType info;
    nodeType<elemType> *lLink;
    nodeType<elemType> *rLink;
};

template <class elemType>
class bSearchTreeType
{
    public:
        //----------------------------------------------------------------------
        /* Overloaded assignment operator.
        */
        const bSearchTreeType<elemType>& operator=
                     (const bSearchTreeType<elemType>& otherTree)
        {
            if (this != &otherTree) // avoid self-copy
            {
                if (root != nullptr)   // if the binary tree is not empty,
                                    // destroy the binary tree
                    destroy(root);

                if (otherTree.root == nullptr) // otherTree is empty
                    root = nullptr;
                else
                    copyTree(root, otherTree.root);
            } // end else

            return *this;
        }

        //----------------------------------------------------------------------
        /* isEmpty() returns whether or not the binary tree is empty.
        */
        bool isEmpty() const
        {
            return (root == nullptr);
        }

        //----------------------------------------------------------------------
        /* inorderTraversal() calls a helper function to do an inorder traversal
        *  of the binary tree.
        */
        void inorderTraversal() const
        {
            inorder(root);
        }

        //----------------------------------------------------------------------
        /* preorderTraversal() calls a helper function to do a preorder
        *  traversal of the binary tree.
        */
        void preorderTraversal() const
        {
            preorder(root);
        }

        //----------------------------------------------------------------------
        /* postorderTraversal() calls a helper function to do a postorder
        *  traversal of the binary tree.
        */
        void postorderTraversal() const
        {
            postorder(root);
        }

        //----------------------------------------------------------------------
        /* treeHeight() returns the height of the tree using a helper function.
        */
        int treeHeight() const
        {
            return height(root);
        }

        //----------------------------------------------------------------------
        /* treeNodeCount() returns the total number of nodes in the binary tree
        *  using a helper function.
        */
        int treeNodeCount() const
        {
            return nodeCount(root);
        }

        //----------------------------------------------------------------------
        /* treeLeavesCount() returns the total number of leaves in the binary
        * tree using a helper function.
        */
        int treeLeavesCount() const
        {
            return leavesCount(root);
        }

        //----------------------------------------------------------------------
        /* destroyTree() destroys the binary tree using a helper function.
        */
        void destroyTree()
        {
            destroy(root);
        }

        //----------------------------------------------------------------------
        /* search() determines if the parameter is in the binary tree and
        *  returns either true or false.
        */
        bool search(const elemType& searchItem) const
        {
            nodeType<elemType> *current;
            bool found = false;

            if (root == nullptr)
            {
                cout << "Cannot search an empty tree." << endl;
            }
            else
            {
                current = root;

                while (current != nullptr && !found)
                {
                    if (current->info == searchItem)
                    {
                        found = true;
                    }
                    else if (current->info > searchItem)
                    {
                        current = current->lLink;
                    }
                    else
                    {
                        current = current->rLink;
                    }
                } // end while
            } // end else

            return found;
        }

        //----------------------------------------------------------------------
        /* insert() inserts the parameter into the binary tree.
        */
        void insert(const elemType& insertItem)
        {
            nodeType<elemType> *current; // pointer to traverse the tree
            nodeType<elemType> *trailCurrent = nullptr; // pointer behind
                                                        // current
            nodeType<elemType> *newNode; // pointer to create the node

            newNode = new nodeType<elemType>;
            newNode->info = insertItem;
            newNode->lLink = nullptr;
            newNode->rLink = nullptr;

            if (root == nullptr)
            {
                root = newNode;
            }
            else
            {
                current = root;

                while (current != nullptr)
                {
                    trailCurrent = current;

                    if (current->info == insertItem)
                    {
                        cout << "The item to be inserted is already ";
                        cout << "in the tree -- duplicates are not "
                            << "allowed." << endl;
                        return;
                    }
                    else if (current->info > insertItem)
                    {
                        current = current->lLink;
                    }
                    else
                    {
                        current = current->rLink;
                    }
                } // end while

                if (trailCurrent->info > insertItem)
                {
                    trailCurrent->lLink = newNode;
                }
                else
                {
                    trailCurrent->rLink = newNode;
                }
            }
        }

        //----------------------------------------------------------------------
        /* deleteNode() deletes the parameter from the binary tree.
        */
        void deleteNode(const elemType& deleteItem)
        {
            nodeType<elemType> *current; // pointer to traverse the tree
            nodeType<elemType> *trailCurrent; // pointer behind current
            bool found = false;

            if (root == nullptr)
            {
                cout << "Cannot delete from an empty tree." << endl;
            }
            else
            {
                current = root;
                trailCurrent = root;

                while (current != nullptr && !found)
                {
                    if (current->info == deleteItem)
                    {
                        found = true;
                    }
                    else
                    {
                        trailCurrent = current;

                        if (current->info > deleteItem)
                        {
                            current = current->lLink;
                        }
                        else
                        {
                            current = current->rLink;
                        }
                    }
                } // end while

                if (current == nullptr)
                {
                    cout << "The item to be deleted is not in the tree."
                        << endl;
                }
                else if (found)
                {
                    if (current == root)
                    {
                        deleteFromTree(root);
                    }
                    else if (trailCurrent->info > deleteItem)
                    {
                        deleteFromTree(trailCurrent->lLink);
                    }
                    else
                    {
                        deleteFromTree(trailCurrent->rLink);
                    }
                }
                else
                {
                    cout << "The item to be deleted is not in the tree."
                        << endl;
                }
            }
        }

        //----------------------------------------------------------------------
        /* minVal() returns the smallest value in the BST.
        */
        elemType minVal()
        {
            return findMin(root);
        }

        //----------------------------------------------------------------------
        /* maxVal() returns the largest value in the BST.
        */
        elemType maxVal()
        {
            return findMax(root);
        }

        //----------------------------------------------------------------------
        /* Copy constructor
        */
        bSearchTreeType(const bSearchTreeType<elemType>& otherTree)
        {
            if (otherTree.root == nullptr) //otherTree is empty
            {
                root = nullptr;
            }
            else
            {
                copyTree(root, otherTree.root);
            }
        }

        //----------------------------------------------------------------------
        /* Default constructor.
        */
        bSearchTreeType()
        {
            root = nullptr;
        }

        //----------------------------------------------------------------------
        /* Destructor
        */
        ~bSearchTreeType()
        {
            destroy(root);
        }

    private:
        nodeType<elemType>  *root;

        //----------------------------------------------------------------------
        /* copyTree() makes a copy of the binary tree otherTreeRoot points to,
        *  such that copiedTreeRoot points to the copy.
        */
        void copyTree(nodeType<elemType>* &copiedTreeRoot,
                      nodeType<elemType>* otherTreeRoot)
        {
            if (otherTreeRoot == nullptr)
            {
                copiedTreeRoot = nullptr;
            }
            else
            {
                copiedTreeRoot = new nodeType<elemType>;
                copiedTreeRoot->info = otherTreeRoot->info;
                copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
                copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
            }
        }

        //----------------------------------------------------------------------
        /* destroy() destroys the binary tree the parameter p points to.
        */
        void destroy(nodeType<elemType>* &p)
        {
            if (p != nullptr)
            {
                destroy(p->lLink);
                destroy(p->rLink);
                delete p;
                p = nullptr;
            }
        }

        //----------------------------------------------------------------------
        /* inorder() does an inorder traversal of the binary tree the parameter
        *  p points to.
        */
        void inorder(nodeType<elemType> *p) const
        {
            if (p != nullptr)
            {
                inorder(p->lLink);
                cout << p->info << " ";
                inorder(p->rLink);
            }
        }

        //----------------------------------------------------------------------
        /* preorder() does a preorder traversal of the binary tree the parameter
        *  p points to.
        */
        void preorder(nodeType<elemType> *p) const
        {
            if (p != nullptr)
            {
                cout << p->info << " ";
                preorder(p->lLink);
                preorder(p->rLink);
            }
        }

        //----------------------------------------------------------------------
        /* postorder() does a postorder traversal of the binary tree the
        *  parameter p points to.
        */
        void postorder(nodeType<elemType> *p) const
        {
            if (p != nullptr)
            {
                postorder(p->lLink);
                postorder(p->rLink);
                cout << p->info << " ";
            }
        }

        //----------------------------------------------------------------------
        /* height() determines the height of the binary tree the parameter p
        *  points to.
        */
        int height(nodeType<elemType> *p) const
        {
            if (p == nullptr)
            {
                return 0;
            }
            else
            {
                return 1 + max(height(p->lLink), height(p->rLink));
            }
        }

        //----------------------------------------------------------------------
        /* max() determines which of the parameters is larger and returns the
        *  larger of the two.
        */
        int max(int x, int y) const
        {
            if (x >= y)
            {
                return x;
            }
            else
            {
                return y;
            }
        }

        //----------------------------------------------------------------------
        /* nodeCount() returns the total number of nodes in the binary tree the
        *  parameter p points to.
        */
        int nodeCount(nodeType<elemType> *p) const
        {
            if (p == nullptr)
            {
                return 0;
            }
            else
            {
                return 1 + nodeCount(p->lLink) + nodeCount(p->rLink);
            }
        }

        //----------------------------------------------------------------------
        /* leavesCount() returns the total number of leaves in the binary tree
        *  the parameter p points to.
        */
        int leavesCount(nodeType<elemType> *p) const
        {
            if (p == nullptr)
            {
                return 0;
            }
            else if (p->lLink == nullptr && p->rLink == nullptr)
            {
                return 1;
            }
            else
            {
                return leavesCount(p->lLink) + leavesCount(p->rLink);
            }
        }

        //----------------------------------------------------------------------
        /* findMin() finds the smallest value in the BST.
        */
        elemType findMin(nodeType<elemType>* p)
        {
            if (p == nullptr)
            {
                cout << "No minimum value in an empty tree." << endl;
                return elemType();
            }
            else if (p->lLink == nullptr)
            {
                return p->info;
            }
            else
            {
                return findMin(p->lLink);
            }
        }

        //----------------------------------------------------------------------
        /* findMax() finds the largest value in the BST.
        */
        elemType findMax(nodeType<elemType>* p)
        {
            if (p == nullptr)
            {
                cout << "No maximum value in an empty tree." << endl;
                return elemType();
            }
            else if (p->rLink == nullptr)
            {
                return p->info;
            }
            else
            {
                return findMax(p->rLink);
            }
        }

        //----------------------------------------------------------------------
        /* deleteFromTree() deletes the node the parameter p points to from the
        *  binary tree.
        */
        void deleteFromTree(nodeType<elemType>* &p)
        {
            nodeType<elemType> *current; //pointer to traverse the tree
            nodeType<elemType> *trailCurrent;  //pointer behind current
            nodeType<elemType> *temp;      //pointer to delete the node

            if (p == nullptr)
            {
                cout << "Error: The node to be deleted does not exist." << endl;
            }
            else if (p->lLink == nullptr && p->rLink == nullptr)
            {
                temp = p;
                p = nullptr;
                delete temp;
            }
            else if (p->lLink == nullptr)
            {
                temp = p;
                p = temp->rLink;
                delete temp;
            }
            else if (p->rLink == nullptr)
            {
                temp = p;
                p = temp->lLink;
                delete temp;
            }
            else
            {
                current = p->lLink;
                trailCurrent = nullptr;

                while (current->rLink != nullptr)
                {
                    trailCurrent = current;
                    current = current->rLink;
                } // end while

                p->info = current->info;

                if (trailCurrent == nullptr) // current did not move;
                                       // current == p->lLink; adjust p
                {
                    p->lLink = current->lLink;
                }
                else
                {
                    trailCurrent->rLink = current->lLink;
                }

                delete current;
            } // end else
        }
};

#endif
