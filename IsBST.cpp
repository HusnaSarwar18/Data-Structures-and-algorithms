#include <iostream>
using namespace std;
#include <stack>
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class BT
{
public:
    node *root;
    BT()
    {
        this->root = NULL;
    }
    void setRoot(int data)
    {
        if (root == NULL)
        {
            root = new node(data);
        }
    }
    node *getRoot()
    {
        return root;
    }
    node *creat(node *root)
    {
        int data;
        cout << "\nEnter data: ";
        cin >> data;
        root = new node(data);
        if (data == -1)
        {
            return NULL;
        }
        cout << "\nEnter data for insertion in left: " << data;
        root->left = creat(root->left);

        cout << "\nEnter data for insertion in right: " << data;
        root->right = creat(root->right);
        return root;
    }
    void preOrder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            cout << root->data << "->";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    bool isBST(node *root)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->left != NULL && root->left->data < root->data)
        {
            isBST(root->left);
        }
        if (root->right != NULL && root->right->data > root->data)
        {
            isBST(root->right);
        }
        return (isBST(root->left) && isBST(root->right));
    }
};
int main()
{
    BT t;
    t.root = t.creat(t.root);
    cout << "\nPre-order traversal: ";
    t.preOrder(t.root);
    if (t.isBST(t.root))
    {
        cout << "\nIts Binary search tree.";
    }
    else
    {
        cout << "\nIts not Binary search tree.";
    }
}
