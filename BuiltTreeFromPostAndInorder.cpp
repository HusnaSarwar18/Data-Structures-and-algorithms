#include <iostream>
using namespace std;

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

    int search(int in[], int inStart, int inend, int current)
    {
        for (int i = inStart; i <= inend; i++)
        {
            if (in[i] == current)
            {
                return i;
            }
        }
        return -1;
    }

    node *buildTreeFromPostAndInorder(int post[], int in[], int InStart, int InEnd, int &index)
    {
        if (InStart > InEnd)
        {
            return NULL;
        }

        int current = post[index];
        index--;

        node *newnode = new node(current);

        if (InStart == InEnd)
        {
            return newnode;
        }

        int posInInorder = search(in, InStart, InEnd, current);
        newnode->right = buildTreeFromPostAndInorder(post, in, posInInorder + 1, InEnd, index);
        newnode->left = buildTreeFromPostAndInorder(post, in, InStart, posInInorder - 1, index);

        return newnode;
    }

    void Inorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        Inorder(root->left);
        cout << root->data << "->";
        Inorder(root->right);
    }
};

int main()
{
    int *postArray;
    int *inArray;
    int size;
    cout << "\nEnter size of arrays: ";
    cin >> size;

    while (size < 0)
    {
        cout << "\nInvalid size. Enter again: ";
        cin >> size;
    }

    postArray = new int[size];
    inArray = new int[size];

    cout << "\nEnter elements of postOrder Array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> postArray[i];
    }

    cout << "\nEnter elements of InOrder Array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> inArray[i];
    }

    BT b;
    int index = size - 1; // Start index for postorder traversal
    b.root = b.buildTreeFromPostAndInorder(postArray, inArray, 0, size - 1, index);

    cout << "\nInorder Traversal of the built tree: " << endl;
    b.Inorder(b.root);

    return 0;
}
