#include<iostream>
#include<string>
using namespace std;

void replace(string s){
    if(s.size() == 0){
        return;
    }
    if(s[0] == 'o' && s[1] == 'o'){
        cout << "kmit";
        replace(s.substr(2));
    }
    else{
        cout << s[0];
        replace(s.substr(1));
    }
    return;
}

int main()
{
    string s = "goozeldoopsoococoofl";
    replace(s);
    return 0 ;
}