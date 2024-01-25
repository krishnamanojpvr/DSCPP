#include <iostream>
using namespace std;
#define SIZE 1000
void max_Heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    if (leftChild < n && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }
    if (rightChild < n && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        max_Heapify(arr, n, largest);
    }
}
void maxHeap(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        max_Heapify(arr, n, i);
    }
}
void insert(int arr[], int &n, int val)
{
    n = n + 1;
    arr[n - 1] = val;
    maxHeap(arr, n);
}
void deleteRoot(int arr[], int &n)
{
    arr[0] = arr[n - 1];
    n = n - 1;
    max_Heapify(arr, n, 0);
}
int peek(int arr[])
{
    return arr[0];
}
int extractMaximum(int arr[], int &n)
{
    int max = arr[0];
    std::swap(arr[0], arr[n - 1]);
    n = n - 1;
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        max_Heapify(arr, n, i);
    }
    return max;
}
void printArray(int arr[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[SIZE] = {10, 7, 8, 5, 6};
    int n = 5;
    printArray(arr, n);
    insert(arr, n, 11);
    printArray(arr, n);
    insert(arr, n, 20);
    printArray(arr, n);
    deleteRoot(arr, n);
    printArray(arr, n);
    cout << extractMaximum(arr, n) << endl;
    printArray(arr, n);
    return 0;
}