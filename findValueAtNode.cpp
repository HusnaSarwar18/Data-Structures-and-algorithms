#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class BST
{
public:
    int *arr;
    Node *root;
    BST()
    {
        this->root = NULL;
    }
    Node *insert(Node *root, int value)
    {
        if (root == NULL)
        {
            return new Node(value);
        }

        if (value < root->data)
        {
            root->left = insert(root->left, value);
        }
        else if (value > root->data)
        {
            root->right = insert(root->right, value);
        }

        return root;
    }
    void inorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
    int findValueAtNode(Node *root, int nodeNumber)
    {
        if (root == NULL || nodeNumber <= 0)
        {
            cerr << "Invalid node number!" << endl;
            return -1;
        }

        while (nodeNumber > 1)
        {
            if (nodeNumber % 2 == 0)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
            nodeNumber /= 2;
        }

        return root->data;
    }
};