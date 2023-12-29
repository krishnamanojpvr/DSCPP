#include<iostream>
using namespace std;

void reverse(string s){
    if(s.size() == 0){
        return;
    }
    reverse(s.substr(1));
    cout << s[0];
}

int main()
{
    string s = "hello";

    reverse(s);

    return 0 ;
}