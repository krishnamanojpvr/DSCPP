// Automorphic number is a number whose square ends in the same digits as the number itself

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int sqN = n*n;
    cout<<"Square : "<<sqN<<endl;
    int temp = sqN;
    int rem = 0;
    double lastD = 0;
    int i = 0;
    while(temp != 0){
        rem = temp%10;
        lastD = lastD + rem*pow(10,i);
        cout << lastD << endl;
        temp = temp/10;
        i++;
        if(lastD == n){
            cout << "Automorphic";
            return 0;
        }
    }
    cout << "Not Automorphic";
    return 0 ;
}


















