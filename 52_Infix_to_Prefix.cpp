#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int precedence(char c)
{
	if (c == '^')
	{
		return 3;
	}
	if (c == '/' || c == '*')
	{
		return 2;
	}
	if (c == '+' || c == '-')
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

char associativity(char c)
{
	if (c == '^')
	{
		return 'R';
	}
	return 'L';
}

string infixToPrefix(string s)
{
	stack<char> st;
	string result = "";
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		{
			result += c;
		}
		else if (c == ')')
		{
			st.push(c);
		}
		else if (c == '(')
		{
			while (st.top() != ')')
			{
				result += st.top();
				st.pop();
			}
			st.pop();
		}
		else
		{
			while (!st.empty() && ((precedence(c) < precedence(st.top())) || (precedence(c) == precedence(st.top()) && associativity(c) == 'L')))
			{
				result += st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	while (!st.empty())
	{
		result += st.top();
		st.pop();
	}

	return result;
}

int main()
{
	string s;
	cout<<"Enter an infix expression : ";
	cin>>s;
    reverse(s.begin(),s.end());
	string result=infixToPrefix(s);
    reverse(result.begin(),result.end());
    cout<<result<<endl;
	return 0;
}
