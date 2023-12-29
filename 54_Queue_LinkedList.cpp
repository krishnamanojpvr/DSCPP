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

class Queue{
    Node *front;
    Node *rear;
    public:
        Queue(int data){
            Node *newnode = new Node(data);
            front = newnode;
            rear = newnode;
        }
        Queue(){
            front = NULL;
            rear = NULL;
        }
        void enQueue(int data){
            Node *newnode = new Node(data);
            rear->next = newnode;
            rear = newnode;
        }
        void deQueue(){
            Node *temp =front;
            front = front->next;
            delete temp;
        }
        void Display(){
            if(front==NULL){
                cout<<"Queue is Empty"<<endl;
                return;
            }
            Node* temp = front;
            while(temp!=rear){
                cout<<temp->data<<"->";
                temp = temp->next;
            }
            cout<<rear->data<<endl;
            return;

        }
};

int main()
{
    Queue q1(10);
    q1.Display();
    q1.enQueue(15);
    q1.enQueue(20);
    q1.enQueue(30);
    q1.Display();
    q1.deQueue();
    q1.Display();
    q1.deQueue();
    q1.Display();
    return 0;
}