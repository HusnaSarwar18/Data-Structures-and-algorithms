// circular queue using linklist
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
class Queue
{
private:
    node *front;
    node *rear;

public:
    Queue()
    {
        this->front = NULL;
        this->rear = NULL;
    }
    void enqueue(int data)
    {
        node *newnode = new node(data);
        newnode->next_add = NULL;
        if (front == NULL && rear == NULL)
        {
            front = rear = newnode;
            rear->next_add = newnode;
        }
        else
        {
            rear->next_add = newnode;
            newnode->next_add = front;
            rear = newnode;
        }
    }
    void dequeue()
    {
        if (front == NULL && rear == NULL)
        {
            cout << "\nNothing to delete.";
            return;
        }
        else
        {
            node *temp = front;
            front = front->next_add;
            rear->next_add = front;
            delete temp;
        }
    }
    // int front()
    // {
    //     if (front == NULL && rear == NULL)
    //     {
    //         return -1;
    //     }
    //     else
    //     {
    //         return front->data;
    //     }
    // }
    void dispaly()
    {
        if (front == NULL && rear == NULL)
        {
            cout << "\nNothing to display.";
            return;
        }
        else
        {
            cout << "\nThe elements of queue are: ";
            node *temp = front;
            do
            {
                cout << temp->data << "->";
                temp = temp->next_add;
            } while (temp != front);
        }
    }
};
int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dispaly();
    q.dequeue();
    q.dispaly();
}
