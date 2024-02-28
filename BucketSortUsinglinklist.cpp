#include <iostream>
using namespace std;
class node
{
public:
    float data;
    node *next;
    node(float data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class LinkList
{
    node *head;

public:
    LinkList()
    {
        this->head = NULL;
    }
    void insertion(float value)
    {
        node *newnode = new node(value);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL && temp->next->data < value)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
    float begin()
    {
        if (head == NULL)
            return 0;
        else
        {
            float r = head->data;
            node *temp = head;
            head = head->next;
            delete temp;
            return r;
        }
    }
};
float bucketSort(float arr[], int size)
{
    LinkList *buckets = new LinkList[size];
    for (int i = 0; i < size; i++)
    {
        buckets[int(size * arr[i])].insertion(arr[i]);
    }
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        while (!buckets[i].isEmpty())
        {
            arr[index++] = buckets[i].begin();
        }
    }
}
void display(float arr[], int size)
{
    cout << "\nThe elements of an array are: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "->";
    }
}
int main()
{
    int size;
    float *arr;
    cout << "\nEnter size: ";
    cin >> size;
    arr = new float[size];
    for (int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    bucketSort(arr, size);
    display(arr, size);
    return 0;
}
