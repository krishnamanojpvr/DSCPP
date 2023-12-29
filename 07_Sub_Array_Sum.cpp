#include<iostream>
using namespace std;

int main()
{
    int sum = 0;
    int num;
    cin >> num;
    int arr[5] = {1,2,3,4,5};
    for(int i = 0; i<5; i++){
        for(int j = i; j<5; j++){
        sum = 0;
            for(int k = i; k<=j;k++){
                sum += arr[k];
            }
            cout << sum << endl;
            if(sum == num){
            cout << "Yes" << endl;
            return 0;
        }
        }
       
    }
    cout << "No" << endl;
    return 0;
    
    
}