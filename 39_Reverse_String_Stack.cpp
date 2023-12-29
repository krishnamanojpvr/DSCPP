#include<iostream>
using namespace std;
class Node{
    public:
        char data;
        Node *next=NULL;
        Node(char data){
            this->data = data;
            this->next = NULL;
        }
};
class Stack{
    Node * top;
    public:
    Stack(char data){
        Node *newnode = new Node(data);
        top = newnode;
    }
    Stack(){
        top = NULL;
    }
    void Push(char data);
    Node* Pop();
    void Display();

};

void Stack::Push(char data){
    Node *newnode = new Node(data);
    newnode->next = top;
    top = newnode;
}

Node* Stack::Pop(){
    char revChar;
    Node * temp = top;
    top = temp->next;
    return temp;
}



int main()
{
    cout<<"Enter a string : ";
    string s;
    // cin>>s;
    getline(cin,s);
    string revS;
    char revChar;
    Stack st;
    for(int i=0; i<s.size();i++){
        st.Push(s[i]);
    }
    cout<<"Reversed String : "<<revS<<endl;
    for(int i=0;i<s.size();i++){
        cout<<st.Pop()->data;
    }
    return 0;
}