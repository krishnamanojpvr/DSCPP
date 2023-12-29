#include<iostream>
using namespace std;

int fun1(int n){
    if(n==1){
        return 0;
    }
    else{
        return 1 + fun1(n/2);
    }
}

int main()
{
    cout << fun1(5) << endl;
    return 0 ;
}