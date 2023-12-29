#include<iostream>
using namespace std;

class Array{
    public:
        int element;  
        int n = 5; 
        int *arr = new int[n];
        void inArr(){
            int i = 0;
            while(i<n){
                cout << "Enter coefficient of " << n-i-1 << endl;
                cin >> element;
                arr[i] = element;
                i++;
            }
        }
        void display();
        
};


void Array :: display(){
    cout << "Polynomial is" << endl;
    for(int i = 0; i<n; i++){
        if(i != n-1 && arr[i] != 0){
            cout << arr[i]  << "x" << n-i-1 << "+";
        }
        else if(i == n-1){
            cout << arr[i];
        }
        
    }
    delete[] arr;
}

int main()
{
    Array a;
    a.inArr();
    a.display();
    return 0 ;
}