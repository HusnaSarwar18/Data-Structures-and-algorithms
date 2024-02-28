#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next_add;
    node(int data)
    {
        this->data = data;
        this->next_add = NULL;
    }
};
class SLL
{
private:
    node *top;

public:
    SLL()
    {
        this->top = NULL;
    }
    void push(int data)
    {
        node *newnode = new node(data);
        newnode->next_add = NULL;
        if (top == NULL)
        {
            top = newnode;
        }
        else
        {
            newnode->next_add = top;
            top = newnode;
        }
    }
    void display()
    {
        node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next_add;
        }
    }
    int peek()
    {
        return top->data;
    }
    void pop()
    {
        node *temp = top;
        cout << "\nThe value " << top->data << " has been removed-" << endl;
        top = top->next_add;
        delete temp;
    }
};
int main()
{
    SLL l;
    l.push(3);
    l.push(2);
    l.push(1);
    cout << "\nThe peek value of the stack is: " << l.peek();
    cout << "\n The elements of the stack are: " << endl;
    l.display();
    l.pop();
    cout << "\nSo the remaining elements are: " << endl;
    l.display();
}