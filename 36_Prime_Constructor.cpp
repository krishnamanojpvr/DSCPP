/*Write a CPP program to print a number is prime number or not

Sample Input-Output:

Enter the Number:7                                                                                                      
7 is Prime Number.                                                                                                      

Enter the Number:6                                                                                                      
6 is Not Prime Numbers.                                                                                                 
                                               


*/

#include<iostream>
using namespace std;

class Number{
    int num;
    public:
    Number(){
        cout << "Enter the Number:";
        cin >> num;
        int flag = 0;
        for(int i = 2; i<num; i++){
            if(num%i == 0){
                cout << num << " is Not Prime Numbers.";
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout << num << " is Prime Number.";
        }
    }
};

int main(){
    Number n;
    return 0;
}