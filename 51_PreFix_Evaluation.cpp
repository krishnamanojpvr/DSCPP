#include<iostream>
#include<stack>
#include<typeinfo>
using namespace std;

int evaluatePrefix(string s){
    stack<char> st;
    for(int i = s.size()-1; i >=0 ; i--){
        if(isdigit(s[i])){
            st.push(s[i]-'0');
        }
        else{
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(num1+num2);
                break;
            case '-':
                st.push(num1-num2);
                break;
            case '*':
                st.push(num1*num2);
                break;
            case '/':
                st.push(num1/num2);
                break;
            
            default:
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    string s = "+3*21";

    cout << evaluatePrefix(s);
    return 0 ;
}