#include <iostream>
using namespace std;
int linearSearch(int arr[], int size, int val)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    cout<<linearSearch(arr,5,10)+1;
    return 0;
}