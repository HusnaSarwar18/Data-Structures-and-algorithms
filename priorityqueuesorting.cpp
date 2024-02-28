#include <iostream>
using namespace std;

class node
{
public:
    int data;
    int priority;

    node *next_add;
    node(int data, int priority)
    {
        this->data = data;
        this->priority = priority;
        this->next_add = NULL;
    }
};

class PriorityQueueUsingLL
{
private:
    node *front;
    node *rear;

public:
    PriorityQueueUsingLL()
    {
        this->front = NULL;
        this->rear = NULL;
    }
    void enqueue(int data, int priority)
    {
        node *newnode = new node(data, priority);
        if (front == NULL)
        {
            front = newnode;
        }
        else if (priority < front->priority)
        {
            newnode->next_add = front;
            front = newnode;
        }
        else
        {
            node *temp = front;
            while (temp->next_add != NULL && temp->next_add->priority <= priority)
            {
                temp = temp->next_add;
            }
            newnode->next_add = temp->next_add;
            temp->next_add = newnode;
        }
    }
    void deQueue()
    {
        if (front == NULL)
        {
            cout << "\nQueue is empty.";
            return;
        }
        node *temp = front;
        front = front->next_add;
        delete temp;
    }
    int peek()
    {
        if (front == NULL)
        {
            cout << "\nQueue is empty.";
            return -1;
        }
        else
        {
            return front->data;
        }
    }
    void display()
    {
        if (front == NULL)
        {
            cout << "\nNothing to display.";
            return;
        }
        else
        {
            cout << "\nThe elements present in the queue are: ";
            node *temp = front;
            while (temp != NULL)
            {
                cout << temp->data << "->";
                temp = temp->next_add;
            }
        }
    }
    void sort(PriorityQueueUsingLL p)
    {
        PriorityQueueUsingLL p1;
        node *temp1 = this->front;
        node *temp2 = p.front;
        while (temp1 != NULL)
        {
            p1.enqueue(temp1->data, temp1->priority);
            temp1 = temp1->next_add;
        }
        while (temp2 != NULL)
        {
            p1.enqueue(temp2->data, temp2->priority);
            temp2 = temp2->next_add;
        }
        p1.display();
    }
};
int main()
{
    PriorityQueueUsingLL p;
    PriorityQueueUsingLL p1;
    p.enqueue(2, 7);
    p.enqueue(9, 0);
    p.enqueue(4, 9);
    p.enqueue(3, 2);
    p.display();
    p1.enqueue(1, 1);
    p1.enqueue(4, 6);
    p1.enqueue(8, 3);
    p1.display();
    p.sort(p1);
}