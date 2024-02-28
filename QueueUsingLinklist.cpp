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
class LinkListQueue
{
private:
    node *front;
    node *rear;

public:
    LinkListQueue()
    {
        this->front = NULL;
        this->rear = NULL;
    }
    void enqueue(int data)
    {
        node *newnode = new node(data);
        newnode->next_add = NULL;
        if (rear == NULL && front == NULL)
        {
            front = rear = newnode;
        }
        else
        {
            node *temp = rear;
            temp->next_add = newnode;
            rear = newnode;
        }
    }
    void dequeue()
    {
        if (front == rear)
        {
            cout << "\nNothing to delete.";
            return;
        }
        else
        {
            node *temp = front;
            front = front->next_add;
            delete temp;
        }
    }
    void display()
    {
        if (rear == NULL && front == NULL)
        {
            cout << "\nNothing to display.";
            return;
        }
        else
        {
            cout << "\nThe elements of queue are: ";
            node *temp = front;
            while (temp != NULL)
            {
                cout << temp->data << "->";
                temp = temp->next_add;
            }
        }
    }
};
int main()
{
    LinkListQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
}