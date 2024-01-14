#include <iostream>
using namespace std;
int binarySearch(int arr[], int left, int right, int val)
{
    while (left <= right)
    {
        int mid = (left + (right - 1)) / 2;
        if (val > arr[mid])
        {
            left = mid + 1;
        }
        else if (val < arr[mid])
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
        return 0;
}