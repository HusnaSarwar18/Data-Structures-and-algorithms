#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
float *input(float arr[], int size)
{
    cout << "\nEnter elements of an array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    return arr;
}
void display(float arr[], int size)
{
    cout << "\nThe elements of an array are: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "->";
    }
}
float *bucketSort(float arr[], int size)
{
    vector<float> buckets[size];
    // buckets
    for (int i = 0; i < size; i++)
    {
        buckets[int(size * arr[i])].push_back(arr[i]);
    }
    cout << " * ";
    // sorting
    for (int i = 0; i < size; i++)
    {
        sort(buckets[i].begin(), buckets[i].end());
    }
    cout << " * ";
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        while (!buckets[i].empty())
        {
            arr[index++] = *buckets[i].begin();
            buckets[i].erase(buckets[i].begin());
        }
    }
    cout << " * ";
    return arr;
}
int main()
{
    int size;
    float *arr;
    cout << "\nEnter size: ";
    cin >> size;
    arr = new float[size];
    arr = input(arr, size);
    cout << " * ";
    arr = bucketSort(arr, size);
    display(arr, size);
    return 0;
}