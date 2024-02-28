// count number of nodes in bt
#include <iostream>
#include <queue>
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
    node *create(node *root)
    {
        int data;
        cin >> data;
        root = new node(data);
        if (data == -1)
        {
            return NULL;
        }
        else
        {
            cout << "\nEnter data to set at left of " << data << ": ";
            root->left = create(root->left);
            cout << "\nEnter data to set at right of " << data << ": ";
            root->right = create(root->right);
            return root;
        }
    }
    void DFS(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            cout << root->data << "->";
            DFS(root->left);
            DFS(root->right);
        }
    }
    void BFS(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            queue<node *> q;
            q.push(root);
            while (!q.empty())
            {
                node *newnode = q.front();
                cout << newnode->data << "->";
                q.pop();
                if (newnode->left)
                {
                    q.push(newnode->left);
                }
                if (newnode->right)
                {
                    q.push(newnode->right);
                }
            }
        }
    }
    int countNode(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            return countNode(root->left) + countNode(root->right) + 1;
        }
    }
    int sumNode(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            return sumNode(root->left) + sumNode(root->right) + root->data;
        }
    }
    // calculating height of a BT
    int Height(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            int leftHeight = Height(root->left);
            int rightHeight = Height(root->right);
            return max(leftHeight, rightHeight) + 1;
        }
    }
    // calculating diameter of BT
    int diameter(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            int leftHeight = Height(root->left);
            int rightHeight = Height(root->right);
            int current = leftHeight + rightHeight + 1;
            int leftDiameter = diameter(root->left);
            int rightDiameter = diameter(root->right);
            return max(current, max(leftDiameter, rightDiameter));
        }
    }
    // sum replacement
    void sumReplace(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            sumReplace(root->left);
            sumReplace(root->right);
            if (root->left != NULL)
            {
                root->data += root->left->data;
            }
            if (root->right != NULL)
            {
                root->data += root->right->data;
            }
        }
    }
    bool isBalanced(node *root)
    {
        if (root == NULL)
        {
            return true;
        }
        int leftHeight = Height(root->left);
        int rightHeight = Height(root->right);
        return ((abs(leftHeight - rightHeight) <= 1) && isBalanced(root->left) && isBalanced(root->right));
    }
};
int main()
{
    BT b;
    b.root = b.create(b.root);
    cout << "\nThe total no of nodes in our tree is: " << b.countNode(b.root);
    cout << "\nThe total sum of nodes in our tree is: " << b.sumNode(b.root);
    cout << "\nThe diameter of the tree is: " << b.diameter(b.root) << endl;
    b.DFS(b.root);
    cout << "\nThe answer of sumReplacement is: ";
    b.sumReplace(b.root);
    b.DFS(b.root);
    if (b.isBalanced(b.root))
    {
        cout << "\nThis is a balanced tree." << endl;
    }
    else
    {
        cout << "\nThis is not a balanced tree." << endl;
    }

    return 0;
}