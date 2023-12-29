/*Print all subsequences of a string

SAMPLE INPUT/OUTPUT:
Enter a string: abc
abc
ab
ac
a
bc
b
c

*/
#include<iostream>
#include<string>
using namespace std;

void subS(string s, string curr, int i){
    if(i == s.length()){
        cout << curr << endl;
        return;
    }
    subS(s,curr + s[i],i+1);
    subS(s,curr,i+1);
}

int main(){
    string s;
    cout << "Enter a string:";
    cin >> s;
    subS(s,"",0);
    return 0;
}