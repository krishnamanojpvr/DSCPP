/*
write a c++ program to find the sum of all possible sub arrays
Sample Input-Output:
give array size:
2
Array elements are:
3
2
index from 0 to 0 sum is 3
index from 0 to 1 sum is 5
index from 1 to 1 sum is 2
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "give array size:" << endl;
    cin >> n;
    int arr[n];
    cout << "Array elements are:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            cout << "index from " << i << " to " << j << " sum is " << sum << endl;
        }
    }
    return 0;
}