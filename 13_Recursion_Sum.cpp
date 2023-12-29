#include<iostream>
using namespace std;

int sumA(int n){
    if (n == 1){
        return 1;
    }
    cout << n << endl;
    int k = sumA(n-1);
    cout << k << endl;
    return n+k;
    
}

int main()
{
    cout << sumA(5) << endl;
    return 0 ;
}

