#include<iostream>
using namespace std;
#define N 5
int arr[N];
int front = -1;
int rear = -1;
void en(int x){
    if(front==1 && rear==N-1){
        cout<<"Overflow"<<endl;
    }
    else if(front==-1 && rear==-1){
        front = rear = 0;
        arr[rear] = x;
    }
    else{
        rear++;
        arr[rear] = x;
    }
}
void de(){
    if(front==-1 && rear==-1){
        cout<<"Underflow"<<endl;
    }
    else if(front==rear){
        front = rear = -1;
    }
    else{
        front++;
    }
}
void display(){
    if(front==-1 && rear==-1){
        cout<<"Underflow"<<endl;
    }
    else{
        for(int i=front; i<rear;i++){
            cout<<arr[i]<<",";
        }
        cout<<arr[rear]<<endl;
    }
}
int main()
{
    en(1);
    en(2);
    en(3);
    display();
    de();
    display();
    de();
    display();
    return 0;
}