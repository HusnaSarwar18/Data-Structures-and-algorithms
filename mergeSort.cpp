#include <iostream>
#define size 6
using namespace std;
void mergeSort(int arr[], int p, int q);
void combine(int arr[], int p, int mid, int q);
int main()
{
    int *arr;
    arr = new int[size];
    cout << "\nEnter elements of an array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "\nThe elements of an array are: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    int p = 0;
    int q = size;
    mergeSort(arr, p, q);
    cout << "\nThe array after sorting is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
void mergeSort(int arr[], int p, int q)
{
    int mid = 0;
    if (p < q)
    {
        mid = (p + q) / 2;
        mergeSort(arr, p, mid);
        mergeSort(arr, mid + 1, q);
        combine(arr, p, mid, q);
    }
}
void combine(int arr[], int p, int mid, int q)
{
    int size1 = (mid - p + 1);
    int size2 = q - (mid + 1) + 1;
    int *temp = new int[q - p + 1];
    int k = 0;
    int i = p;
    int j = mid + 1;
    while (i < size1 && i < size2)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i];
            i++;
        }
        else
        {
            temp[k++] = arr[j];
            j++;
        }
    }
}