/*
Write a CPP Program to perferm sum till n numbers using recursion

Sample Input-Output:
enter n:
4
sum is:10

*/
#include <iostream>
using namespace std;
int sumn(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sumn(n - 1);
}
int main()
{
    int n;
    cout << "enter n:" << endl;
    cin >> n;
    int sum = sumn(n);
    cout << "sum is:" << sum << endl;
}