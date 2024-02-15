#include <iostream>
using namespace std;
void countSort(int arr[], int n, int k)
{
    int countArr[k + 1] = {0};
    int brr[n];
    for (int i = 0; i < n; i++)
    {
        ++countArr[arr[i]];
    }
    for (int i = 1; i <= k; i++)
    {
        countArr[i] = countArr[i] + countArr[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        brr[countArr[arr[i]] - 1] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = brr[i];
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
    countSort(arr, n, k);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}