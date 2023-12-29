// Maximum number in array till 'i'th element

#include<iostream>

using namespace std;

int main()
{
    int arr[8] = {1,0,5,3,6,7,-8,10};
    int i;
    cin >> i;   
    int maxN = INT8_MIN;
    for(int j = 0; j<=i; j++){
        // if(arr[j] > maxN){
        //     maxN = arr[j];
        // }
        maxN = max(maxN,arr[j]);
    }
    cout << maxN;
    return 0 ;
}