// level order traversal
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
            cout << "\nEnter data to insert at left of " << data << ": ";
            root->left = create(root->left);
            cout << "\nEnter data to insert at right of " << data << ": ";
            root->right = create(root->right);
            return root;
        }
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
    // levelOrder
    void levelOrder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            node *Node = q.front();
            cout << Node->data << "->";
            q.pop();

            if (Node->left != NULL)
            {
                q.push(Node->left);
            }
            if (Node->right != NULL)
            {
                q.push(Node->right);
            }
        }
    }
    // sumAtKUsingBFS
    int sumAtKUsingBFS(node *root, int k)
    {
        if (root == NULL)
        {
            return -1;
        }
        else
        {
            queue<node *> q;
            q.push(root);
            int level = 0;
            int sum = 0;
            while (!q.empty())
            {
                int size = q.size();
                for (int i = 0; i < size; i++)
                {
                    node *Node = q.front();
                    q.pop();
                    if (level == k)
                    {
                        sum += Node->data;
                    }
                    if (Node->left != NULL)
                    {
                        q.push(Node->left);
                    }
                    if (Node->right != NULL)
                    {
                        q.push(Node->right);
                    }
                }
                level++;
            }
            if (k > level)
            {
                cout << "\n Level k doesn't exist in the tree.";
                return -1; // Level k doesn't exist in the tree
            }

            return sum;
        }
    }
};
int main()
{
    BT b;
    b.root = NULL;
    b.root = b.create(b.root);
    b.Inorder(b.root);
    cout << "\nLevel order traversal: " << endl;
    b.levelOrder(b.root);
    int sum = b.sumAtKUsingBFS(b.root, 2);
    cout << "\nThe sum is: " << sum;
    return 0;
}
