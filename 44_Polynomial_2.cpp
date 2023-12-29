#include<iostream>
using namespace std;

class Array{
    public:
        int element;  
        int degree;
        int n = 5;
        int *arr = new int[n];
        void inArr(){
            while(true){
                cout << "Enter coefficient or enter 0 to exit"<<endl;
                cin >> element;
                if(element == 0){
                    break;
                }
                cout << "Enter degree "<<endl;
                cin >> degree;
                if(degree > n){
                    arr = new int[degree];
                    n = degree;
                }
                arr[degree] = element;
            }
        }
        void display();
        
};


void Array :: display(){
    cout << "Polynomial is" << endl;
    for(int i = n-1; i>=0; i--){
        if(i != 0){
            cout << arr[i]  << "x" << i << " + ";
        }
        else if(i == 0){
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