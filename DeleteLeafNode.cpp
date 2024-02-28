
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
    Node *DeleteLeafNodes(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        root->left = DeleteLeafNodes(root->left);
        root->right = DeleteLeafNodes(root->right);

        return root;
    }
};
int main()
{
    BST t;
    t.root = t.insert(t.root, 20);
    t.root = t.insert(t.root, 10);
    t.root = t.insert(t.root, 30);
    t.root = t.insert(t.root, 5);
    t.root = t.insert(t.root, 15);
    t.root = t.insert(t.root, 25);
    t.root = t.insert(t.root, 35);
    t.inorder(t.root);
    cout << "\nAfter Deleting the root noodes the tree will look like: " << endl;
    t.DeleteLeafNodes(t.root);
    t.inorder(t.root);
    return 0;
}
