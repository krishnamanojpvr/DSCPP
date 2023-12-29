/*
Write a C++ program to find the length of a 
longest arithmetic subarray

SAMPLE INPUT/OUTPUT:
Number of elements:5                                                                                                    
Array elements:                                                                                                         
3 4 5 6 7                                                                                                               
longest arithmetic subarray length:4                                                                                    
 
Number of elements:5                                                                                                    
Array elements:                                                                                                         
6 8 10 15 16                                                                                                            
longest arithmetic subarray length:2                                                                                    

*/

#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int noOfElem;
    cout << "Number of elements:";
    cin >> noOfElem;
    int currDiff = 0;
    int *p = new int[noOfElem];
    int length = 1;
    int maxN = 0;
    currDiff = abs(p[1]-p[0]);
    cout << "Array elements:"<<endl;
    for(int i = 0; i<noOfElem; i++){
        cin >> p[i];
    }
    for(int i = 1; i<noOfElem; i++){
        if(abs(p[i]-p[i-1]) == currDiff){
            length++;
        }
        else{
            currDiff = abs(p[i] - p[i-1]);
            length = 1;
        }
        maxN = max(maxN,length);
        
    }
    cout << "longest arithmetic subarray length:"<<maxN;
    delete[] p;
    return 0;
}