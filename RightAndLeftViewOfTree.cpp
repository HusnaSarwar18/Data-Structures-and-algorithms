// right view of bt
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
    void rightView(node *root)
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
                int size = q.size();
                for (int i = 0; i < size; i++)
                {
                    node *curr = q.front();
                    q.pop();
                    if (i == size - 1)
                    {
                        cout << curr->data << "->";
                    }
                    if (curr->left != NULL)
                    {
                        q.push(curr->left);
                    }
                    if (curr->right != NULL)
                    {
                        q.push(curr->right);
                    }
                }
            }
        }
    }
    void leftView(node *root)
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
                int size = q.size();
                for (int i = 1; i <= size; i++)
                {
                    node *temp = q.front();
                    q.pop();
                    if (i == 1)
                    {
                        cout << temp->data << "->";
                    }
                    if (temp->left != NULL)
                    {
                        q.push(temp->left);
                    }
                    if (temp->right != NULL)
                    {
                        q.push(temp->right);
                    }
                }
            }
        }
    }
};
int main()
{
    BT b;
    b.root = b.create(b.root);
    cout << "\n---DFS---" << endl;
    b.DFS(b.root);
    cout << "\n---Right view of tree:---" << endl;
    b.rightView(b.root);
    cout << "\n---left view of tree:---" << endl;
    b.leftView(b.root);
    return 0;
}