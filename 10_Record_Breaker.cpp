        // Given the number of visitors at her local theme park on N consecutive days. The number of visitors on the ith day is Vi. A day is record breaking if it satisfies both the following conditions :
        // 1. The number of visitors on the day is strictly larger than the number of visitors of the previous days
        // 2. Either it is the largest or number of visitors on the day is stricly larger than the number of visitors on the following day.
        // Note that the very first day could be the record breaking day.
        // Number of record breaking days.

        /*
        create a record breaker program in C++ using arrays to keep track of daily scores.

        Sample Input-Output:
        enter n value:8
        1
        2
        0
        7
        2
        0
        2
        2
        no.of rec brakes:2

        */

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "enter n value:";
    cin >> n;
    int arr[n];
    int count = 0;
    int maxN = INT16_MIN;
    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > maxN)
        {
            maxN = arr[i];
            count++;
        }
        if (arr[0] > arr[i])
        {
            count1++;
        }
    }
    if (count1 == n - 1)
    {
        count++;
    }
    cout << "no.of rec brakes:" << count;
    return 0;
}
