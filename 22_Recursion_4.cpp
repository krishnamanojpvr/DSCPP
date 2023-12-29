#include<iostream>
using namespace std;


void fun2(int n){
    if(n==0){
        return;
    }
    fun2(n/2);
    cout << n%2 << endl;
}
int main()
{
    fun2(4);
    return 0 ;
}