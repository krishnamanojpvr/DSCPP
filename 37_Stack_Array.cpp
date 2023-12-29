#include<iostream>
#define N 5
using namespace std;
int arr[N];
int top = -1;
void push(int x){
    if(top == N-1){
        cout<<"Stack is Full"<<endl;
        return;
    }
    top++;
    arr[top]=x;

}
void pop(){
    if(top == -1){
        cout<<"Stack is Empty"<<endl;
        return;
    }
    top--;
}
int peek(){
    return arr[top];
}
bool isEmpty(){
    if(top==-1){
        return false;
    }
    return true;
}
void display(){
    int i = top;
    while(i>0){
        cout<<arr[i]<<",";
        i--;
    }
    cout<<arr[i]<<endl;
    return;
}
int main()
{
    push(0);
    push(1);
    push(2);
    push(3);
    display();
    pop();
    display();
    pop();
    display();
    cout<<peek()<<endl;
    return 0;
}