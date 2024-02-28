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
    // insert at first
    void insertAtFirst(int data)
    {
        node *newnode = new node(data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }
    // delfromFirst
    void delfromFirst()
    {
        if (head == NULL)
        {
            cout << "\nList is empty.";
            return;
        }
        else
        {
            node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
    }
    // insertAtEnd
    void insertAtEnd(int data)
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
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
    // delFromLast
    void delFromLast()
    {
        if (head == NULL && tail == NULL)
        {
            cout << "\nEmpty list.";
            return;
        }
        if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }
    // insertBefore
    void insertBefore(int sv, int data)
    {
        node *newnode = new node(data);
        newnode->next = NULL;
        newnode->prev = NULL;
        node *temp = head;
        if (sv == temp->data)
        {
            insertAtFirst(data);
            return;
        }
        while (temp->next != NULL && temp->next->data != sv)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            insertAtEnd(data);
            return;
        }
        else
        {
            newnode->next = temp->next;
            temp->next->prev = newnode;
            newnode->prev = temp;
            temp->next = newnode;
        }
    }
    // deleteBefore
    void deleteBefore(int sv)
    {
        node *temp = head;
        if (temp->data == sv)
        {
            delfromFirst();
            return;
        }
        while (temp->next != NULL && temp->next->data != sv)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            delFromLast();
            return;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }
    // deleteAfter
    void deleteAfter(int sv)
    {
        node *temp = head;
        if (temp->data == sv)
        {
            delfromFirst();
            return;
        }
        while (temp->next != NULL && temp->data != sv)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            delFromLast();
            return;
        }
        else
        {
            temp->next->prev = temp;
            temp->next = temp->next->next;
        }
    }
    // insertAfter
    void insertAfter(int sv, int data)
    {
        node *newnode = new node(data);
        newnode->next = NULL;
        newnode->prev = NULL;
        node *temp = head;
        if (temp->data == sv)
        {
            insertAtFirst(data);
            return;
        }
        while (temp->next != NULL && temp->data != sv)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            insertAtEnd(data);
        }
        else
        {
            newnode->next = temp->next;
            temp->next->prev = newnode;
            newnode->prev = temp;
            temp->next = newnode;
        }
    }
    void findPair(int x)
    {
        node *temp = head;
        while (temp != NULL && tail != temp)
        {
            if (temp->data + tail->data == x)
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
    l.findPair(0);
    return 0;
}