#include<iostream>
using namespace std;
#define LIMIT 1000

void fun2(int n){
    if(n<=0){
        return;
    }
    if(n>LIMIT){
        return;
    }
    cout << n << " ";
    fun2(2*n);
    cout << n << " ";
}
int main()
{
    fun2(8);
    return 0 ;
}