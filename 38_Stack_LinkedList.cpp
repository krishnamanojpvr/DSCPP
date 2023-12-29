#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next=NULL;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};
class Stack{
    Node * top;
    public:
    Stack(int data){
        Node *newnode = new Node(data);
        top = newnode;
    }
    Stack(){
        top = NULL;
    }
    void Push(int data);
    void Pop();
    int Peek();
    bool isEmpty();
    int Length();
    void Display();
};

void Stack::Push(int data){
    Node *newnode = new Node(data);
    newnode->next = top;
    top = newnode;
}

void Stack::Pop(){
    Node * temp = top;
    top = temp->next;
    delete temp;
}

int Stack::Peek(){
    return top->data;
}

bool Stack::isEmpty(){
    if(top == NULL){
        return true;
    }
    return false;
}

int Stack::Length(){
    if(top == NULL){
        return 0;
    }
    int count = 0;
    Node *temp = top;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;

}

void Stack::Display(){
    if(top==NULL){
        cout<<"Stack Underflow";
        return;
    }
    Node *temp = top;
    while(temp->next!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}

int main()
{
    Stack s1(10);
    s1.Display();
    s1.Push(20);
    s1.Display();
    cout<<"Length : "<<s1.Length()<<endl;
    cout<<"Top : "<<s1.Peek()<<endl;
    s1.Push(30);
    s1.Push(40);
    s1.Display();
    s1.Pop();
    s1.Display();
    cout<<"Length : "<<s1.Length()<<endl;
    return 0;
}