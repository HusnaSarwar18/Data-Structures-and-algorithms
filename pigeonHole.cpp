#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
void input(float arr[], int size)
{
    cout << "\nEnter elements of an array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
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
float getMax(float arr[], int size)
{
    float max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
float getMin(float arr[], int size)
{
    float min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}
float *bucketSort(float arr[], int size)
{
    int max = getMax(arr,size);
    int min = getMin(arr,size);
    int s = max-min+1;
    vector<float> buckets[s];
    // buckets
    for (int i = 0; i < size; i++)
    {
        buckets[int(arr[i])-min].push_back(arr[i]);
    }
    // sorting
    for (int i = 0; i < size; i++)
    {
        sort(buckets[i].begin(), buckets[i].end());
    }
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        while (!buckets[i].empty())
        {
            arr[index++] = *buckets[i].begin();
        }
    }
    return arr;
}
int main()
{
    int size;
    float *arr;
    cout << "\nEnter size: ";
    cin >> size;
    arr = new float[size];
    input(arr, size);
    bucketSort(arr, size);
    display(arr, size);
    return 0;
}