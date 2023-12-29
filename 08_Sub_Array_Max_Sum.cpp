#include<iostream>
using namespace std;

int main()
{
    int sum;
    int maxNum = INT16_MIN;
    int arr[5] = {1,2,3,4,5};
    for(int i = 0; i<5; i++){
        for(int j = i; j<5; j++){
            sum = 0;
            for(int k = i; k<=j;k++){
                sum += arr[k];
            }
        maxNum = max(maxNum,sum);
        }
        
    }
    cout << "Maximum sum of sub arrays : " << maxNum;
    return 0 ;
}