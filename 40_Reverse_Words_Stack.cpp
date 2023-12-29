#include<iostream>
using namespace std;

class Node2{
    public:
        string val;
        Node2 * link;
        Node2(string data){
            val = data;
            link = NULL;
        }
};

class Stack{
    Node2 * top;
    public:
        Stack(){
            top = NULL;
        }
        void push(string);
        Node2 * pop();
        void display();
};


void Stack :: push(string val){
    Node2 * temp = new Node2(val);
    temp->link = top;
    top = temp;
}


void Stack :: display(){
    Node2 * temp = top;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->link;
    }
}


int main()
{
    
    Stack S;
    string sentence;
    int count = 0;
    string word = "";
    getline(cin,sentence);
    for(int i = 0; i<sentence.length() ; i++){
        if(sentence[i] == ' '){
            S.push(word);
            word = "";
            count ++;
        }
        else{
            word = word + sentence[i];
        }
    } 
    S.push(word);
    S.display();

    return 0 ;
}