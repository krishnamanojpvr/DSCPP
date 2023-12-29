#include<iostream>
using namespace std;
int fun1(int x,int y){
    if(x==0){
        return y;
    }
    else{
        return fun1(x-1,x+y);
    }
}

int main()
{
    cout << fun1(5,2) << endl;
    return 0 ;
}