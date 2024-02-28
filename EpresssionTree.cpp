#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class node
{
public:
    char data;
    node *left;
    node *right;
    node(char data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class expressionTree
{
public:
    node *root;
    expressionTree()
    {
        this->root = NULL;
    }
    bool isOperator(char ch)
    {
        if (ch == '^' || ch == '/' || ch == '*' || ch == '+' || ch == '-')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isOperand(char ch)
    {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    node *create(string str)
    {
        stack<node *> s;
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (isOperand(str[i]))
            {
                node *temp = new node(str[i]);
                s.push(temp);
            }
            else if (isOperator(str[i]))
            {
                node *op = new node(str[i]);
                node *r = s.top();
                s.pop();
                node *l = s.top();
                s.pop();
                op->left = l;
                op->right = r;
                s.push(op);
            }
        }
        return s.top();
    }
    void preOrder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            cout << root->data;
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    void levelOrder(node *root)
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
                node *temp = q.front();
                cout << temp->data << "->";
                q.pop();
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
    }
};
int main()
{
    expressionTree e;
    string str;
    cout << "\nEnter A String: ";
    cin >> str;
    node *root = e.create(str);
    e.preOrder(root);
    cout << "\nLevel order traversal: " << endl;
    e.levelOrder(root);
    return 0;
}