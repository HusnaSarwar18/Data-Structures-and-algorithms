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

class BinaryTree
{
public:
    node *root;
    BinaryTree()
    {
        this->root = NULL;
    }

    node *create(node *root)
    {
        int d;
        cin >> d;
        root = new node(d);
        if (d == -1)
        {
            return NULL;
        }

        cout << "\nEnter data to set at left of " << d << ": ";
        root->left = create(root->left);
        cout << "\nEnter data to insert at right of " << d << ": ";
        root->right = create(root->right);
        return root;
    }

    // preorder
    void preorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << "->";
        preorder(root->left);
        preorder(root->right);
    }

    // inOrder
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

    // postorder
    void postOrder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << "->";
    }

    int search(int in[], int Instart, int Inend, int current)
    {
        for (int i = Instart; i <= Inend; i++)
        {
            if (in[i] == current)
            {
                return i;
            }
        }
        return -1;
    }

    // buildTreeFromPreAndInorder
    node *buildTreeFromPreAndInorder(int pre[], int in[], int inStart, int inEnd)
    {
        int index = 0;
        if (inStart > inEnd)
        {
            return NULL;
        }
        int current = pre[index];
        index++;
        node *newnode = new node(current);
        if (inStart == inEnd)
        {
            return newnode;
        }
        int pos = search(in, inStart, inEnd, current);
        newnode->left = buildTreeFromPreAndInorder(pre, in, inStart, pos - 1);
        newnode->right = buildTreeFromPreAndInorder(pre, in, pos + 1, inEnd);
        return newnode;
    }
};

int main()
{
    BinaryTree b;
    b.root = NULL;

    int *preArray;
    int *inArray;
    int sizeOfPre;
    int sizeOfIn;

    cout << "\nEnter size of preOrder array: ";
    cin >> sizeOfPre;
    while (sizeOfPre <= 0)
    {
        cout << "\nInvalid size. Enter again: ";
        cin >> sizeOfPre;
    }

    cout << "\nEnter size of InOrder array: ";
    cin >> sizeOfIn;
    while (sizeOfIn <= 0)
    {
        cout << "\nInvalid size. Enter again: ";
        cin >> sizeOfIn;
    }

    // Ensure that sizes are equal
    if (sizeOfPre != sizeOfIn)
    {
        cout << "\nSizes of preOrder and InOrder arrays should be equal." << endl;
        return 1; // Exit with an error code
    }

    preArray = new int[sizeOfPre];
    inArray = new int[sizeOfIn];

    cout << "\nEnter elements of preOrder Array: " << endl;
    for (int i = 0; i < sizeOfPre; i++)
    {
        cin >> preArray[i];
    }

    cout << "\nEnter elements of InOrder Array: " << endl;
    for (int i = 0; i < sizeOfIn; i++)
    {
        cin >> inArray[i];
    }

    cout << "\nLet's build a tree from preorder and inorder: " << endl;
    b.root = b.buildTreeFromPreAndInorder(preArray, inArray, 0, sizeOfIn - 1);
    b.Inorder(b.root);

    return 0;
}
