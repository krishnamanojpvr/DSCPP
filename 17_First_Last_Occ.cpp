/* 
Write a CPP program to find the
first occurrence and last occurrence of an array using recursion

Hint:

take array as {4,2,1,2,2,7} print the first and last ocurrence of 2

Sample Output:

first occurrence is
1
last occurrence is
4

*/
#include <iostream>
using namespace std;
int focc(int a[], int n, int key, int i)
{
    if (i == n)
    {
        return -1;
    }
    if (key == a[i])
    {
        return i;
    }
    return focc(a, n, key, i + 1);
}
int locc(int a[], int n, int key, int i)
{
    if (i == n)
    {
        return -1;
    }
    int rest = locc(a, n, key, i + 1);
    if (rest != -1)
    {
        return rest;
    }
    if (a[i] == key)
    {
        return i + 1;
    }
    return -1;
}
int main()
{
    int a[] = {1,1,1,1,1};
    int n = sizeof(a) / sizeof(a[0]);
    int key = 1;
    int first = focc(a, n, key, 0);
    int last = locc(a, n, key, 0);
    if (first != -1)
    {
        cout << "first occurrence is" << endl;
        cout << first << endl;
    }
    if (last != -1)
    {
        cout << "last occurrence is" << endl;
        cout << last - 1<< endl;
    }

    return 0;
}