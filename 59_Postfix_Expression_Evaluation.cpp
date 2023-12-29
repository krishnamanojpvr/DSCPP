#include<iostream>
#include<stack>
using namespace std;
void eval(string s){
	stack<int> st;
	int len = s.size();
	for(int i=0;i<len;i++){
		char c = s[i];
		if(c>='0' && c<='9'){
			st.push(c - '0');
		}
		else{
			int temp1 = st.top();
			st.pop();
			int temp2 = st.top();
			st.pop();
			switch(c){
				case '+':
				st.push(temp1+temp2);
				break;
			}
		}
	}
	cout<<st.top();
	return;
}

using namespace std;
int main()
{
	string s = "93+";
	eval(s);
	return 0;
}