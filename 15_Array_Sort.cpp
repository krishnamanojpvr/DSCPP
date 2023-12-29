/*
Write a C++ program to check whether array is sorted or not.
HINT:Initialize array with {1,6,3,4,5} and check whether an array is 
sorted or not, return 1 if sorted else 0. 

SAMPLE OUTPUT:0

*/
#include<iostream>
using namespace std;
int sorting(int a[],int n){
    if(n==1){
        return -1;
    }
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            return 0;
        }
    }
    return 1;
}
int main(){
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<sorting(a,n)<<endl;
    return 0;
}