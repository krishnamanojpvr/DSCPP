#include<iostream>
using namespace std;

class Array{
    public:
        int element;  
        int n = 5; 
        int *arr1 = new int[n];
        int *arr2 = new int[n];
        void inArr(){
            int i = 0;
            while(i<n){
                cout << "Enter coefficient of degree " << n-i-1 << " of polynomial 1"<< endl;
                cin >> element;
                arr1[i] = element;
                i++;
            }
            i = 0;
            while(i<n){
                cout << "Enter coefficient of " << n-i-1 << " of polynomial 2"<< endl;
                cin >> element;
                arr2[i] = element;
                i++;
            }
        }
        void display();
        void sumP();
        
};


void Array :: display(){
    cout << "Polynomial 1 is" << endl;
    for(int i = 0; i<n; i++){
        if(i != n-1 && arr1[i] != 0){
            cout << arr1[i]  << "x" << n-i-1 << "+";
        }
        else if(i == n-1){
            cout << arr1[i];
        }
    }
    cout << endl;
    cout << "Polynomial 2 is" << endl;
    for(int i = 0; i<n; i++){
        if(i != n-1 && arr2[i] != 0){
            cout << arr2[i]  << "x" << n-i-1 << "+";
        }
        else if(i == n-1){
            cout << arr2[i];
        }
    }
    cout << endl;
}

void Array :: sumP(){
    int *arr3 = new int[n];
    for(int i = 0; i<n; i++){
        arr3[i] = arr1[i] + arr2[i]; 
    }
    for(int i = 0; i<n; i++){
        if(i != n-1 && arr3[i] != 0){
            cout << arr3[i]  << "x" << n-i-1 << "+";
        }
        else if(i == n-1){
            cout << arr3[i];
        }
    }
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
}

int main()
{
    Array a;
    a.inArr();
    a.display();
    a.sumP();
    return 0 ;
}