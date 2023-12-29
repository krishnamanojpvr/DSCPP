#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<char> st;
    string s1 = "({[]})";
    // string s1 = "([{}])";
    // string s1 = "({[}])";
    // string s1 = "[({]})";
    int size = s1.size();
    bool flag = true;
    for(int i = 0; i < size;i++){
        if(s1[i]=='(' || s1[i]=='{' || s1[i]=='['){
            st.push(s1[i]);
        }
        else if(s1[i]==')'){
            if((st.top() == '(') && !st.empty()){
                st.pop();
            }
            else{
                flag = false;
                break;
            }
        }
        else if(s1[i]=='}'){
            if((st.top() == '{') && !st.empty()){
                st.pop();
            }
            else{
                flag = false;
                break;
            }
        }
        else if(s1[i]==']'){
            if((st.top() == '[') && !st.empty()){
                st.pop();
            }
            else{
                flag = false;
                break;
            }
        }
    }
    cout<<flag<<endl;
    return 0;
}