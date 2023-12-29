// Sum of all numbers in a factorial

#include<iostream>
using namespace std;
 
int factorial(int a);
int main()
{
    int n;
    cout << "Enter a number : ";
    cin >>n;
    int sum = 0;
    int i = 0;
    while(i<n){
        sum = sum + factorial(i+1);
        i = i + 1;
    }
    cout <<"Arithmetic Sum of "<<n<<" is "<<sum;
    return 0 ;
}

int factorial(int a){
    if(a == 0){
        return 1;
    }
    else if(a == 1){
        return 1;
    }
    else{
        return a*factorial(a-1);
    }
}