/*
Write a C++ Program to print numbers in
increasing and decreasing order using recursion
Hint: give the value of n

sample input-output:
enter the value of n:5
Decreasing order:
5
4
3
2
1
Increasing order:
1
2
3
4
5

*/
#include <iostream>
using namespace std;
void dec(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        dec(n - 1);
    }
}
void inc(int n)
{
    if (n > 0)
    {
        inc(n - 1);
        cout << n << endl;
    }
}
int main()
{
    int n;
    cout << "enter the value of n:";
    cin >> n;
    cout << "Decreasing order:" << endl;
    dec(n);
    cout << "Increasing order:" << endl;
    inc(n);
    return 0;
}