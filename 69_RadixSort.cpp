#include <iostream>
using namespace std;
int getMax(int arr[], int n)
{
    int maxN = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxN = max(maxN, arr[i]);
    }
    return maxN;
}
void countSort(int arr[], int n, int pos)
{
    int countArr[10] = {0};
    int brr[n];
    for (int i = 0; i < n; i++)
    {
        countArr[(arr[i] / pos) % 10]++;
    }

    for (int i = 1; i <= 9; i++)
    {
        countArr[i] = countArr[i] + countArr[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        brr[countArr[(arr[i] / pos) % 10] - 1] = arr[i];
        countArr[(arr[i] / pos) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = brr[i];
    }
}
void radixSort(int arr[], int n)
{
    int maxi = getMax(arr, n);
    for (int pos = 1; maxi / pos > 0; pos *= 10)
    {
        countSort(arr, n, pos);
    }
}
int main()
{
    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int k = 9;
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    cout << endl;
    radixSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}