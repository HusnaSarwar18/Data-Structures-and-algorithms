#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
// linklist class
class DublyLinkList
{
private:
    node *head;
    node *tail;

public:
    DublyLinkList()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    void create(int data)
    {
        node *newnode = new node(data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL && tail == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
        }
    }
    void display()
    {
        if (head == NULL && tail == NULL)
        {
            cout << "\nNothing to display. As List is empty-";
            return;
        }
        else
        {
            cout << "\nElements of list is: ";
            node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
        }
    }

    void findPair(int x)
    {
        node *temp = head;
        while (temp != NULL && temp != tail)
        {
            if (temp->data - tail->data == x)
            {
                cout << "(" << temp->data << "," << tail->data << ")";
                temp = temp->next;
                tail = tail->prev;
            }

            else
            {
                cout << "\nPair not found.";
                return;
            }
        }
    }
};
int main()
{
    DublyLinkList l;
    l.display();
    l.create(1);
    l.create(2);
    l.create(3);
    l.create(4);
    l.create(5);
    l.create(6);
    l.display();
    l.findPair(7);
    return 0;
}