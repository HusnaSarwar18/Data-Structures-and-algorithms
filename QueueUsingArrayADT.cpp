#include <iostream>
#define size 6
using namespace std;
class Queue
{
private:
    int *arr;
    int front;
    int rear;

public:
    Queue()
    {
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "\nQueue is full.";
            return;
        }
        else
        {
            if (front == -1 && rear == -1)
            {
                front++;
                rear++;
                arr[rear] = data;
            }
            else
            {
                rear++;
                arr[rear] = data;
            }
        }
    }
    int first()
    {
        if (isEmpty())
        {
            cout << "\nQueue is Empty.";
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
    void deQueue()
    {
        if (isEmpty())
        {
            cout << "\nQueue is already empty.";
            return;
        }
        else if (front == front)
        {
            rear = front = -1;
        }
        {
            front++;
        }
    }
    bool isFull()
    {
        if (rear == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEmpty()
    {
        if (front == -1 || front > rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "\nNoting to display.";
            return;
        }
        else
        {
            cout << "\nThe elements present in the queue are: ";
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << "  ";
            }
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
    q.display();
    cout << "\nthe first element of the queue is: " << q.first() << endl;
    cout << q.isFull();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.display();
    cout << endl;
    cout << q.isEmpty();
}