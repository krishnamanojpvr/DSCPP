#include<iostream>
using namespace std;

void reverse(string s, int n){
    if(n < 0){
        return;
    }
    string a  = s.substr(n);
    cout << a[0];
    reverse(s,n-1);
}

int main()
{
    string s = "hello";
    int n = s.size()-1;

    reverse(s,n);

    return 0 ;
}