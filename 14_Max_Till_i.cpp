/*
Write a c++ program to read n elements in array and 
print max element till ith position


Hint::

   read n elements in array and take a temporary variable intialize
   it to zero then read elements from array and compare each element
   with temporary variable which is greater store it in temporary variable 
   repeat it till end of the loop

sample  input:
6
0 -9 1 3 -4 5
sample output:
0
0
1
3
3
5
*/

#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    int maxN = 0;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    for(int i = 0;i<n; i++){
        if(arr[i] > maxN){
            maxN = arr[i];
        }
        cout << maxN << endl;
    }
    return 0;
}


