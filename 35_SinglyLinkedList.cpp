#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList();
    SinglyLinkedList(int arr[], int size);
    // ~SinglyLinkedList();
    void Display();
    void Insert(int data, int pos);
    void Delete(int pos);
    void Reverse();
    int Length();
    void InsertAtBeginning(int data);
    void InsertAtEnd(int data);
    bool DetectCycle();
};

SinglyLinkedList::SinglyLinkedList(int arr[], int size)
{

    Node *temp, *last ,*newnode;
    newnode = new Node;
    newnode->data = arr[0];
    head=newnode;
    last = head;
    for (int i = 1; i < size; i++)
    {
        temp = new Node;
        temp->data = arr[i];
        last->next = temp;
        last = temp;
    }
}

void SinglyLinkedList::Display()
{
    Node *temp;
    temp = head;
    
    while (temp->next != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }  
    cout<<temp->data << endl;

}

void SinglyLinkedList::Insert(int data, int pos)
{
    Node *temp;
    Node *newnode = new Node;
    newnode->data = data;
    
    if (pos < 1 || pos > Length())
    {
        return;
    }

    else if (pos == 1)
    {
        InsertAtBeginning(data);
    }

    // else if (pos == Length()+1)
    // {
    //     InsertAtEnd(data);
    // }

    else
    {
        temp = head;
        for (int i = 0; i < pos - 2; i++)
        {
            temp = temp->next;
        }

        
        newnode->next = temp->next;
        temp->next = newnode;
    }
};
bool SinglyLinkedList::DetectCycle(){
    Node *slow,*fast;
    slow = fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;

}

int SinglyLinkedList::Length()
{
    if (head == NULL)
    {
        return 0;
    }
    Node *temp = head;
    int count = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void SinglyLinkedList::InsertAtBeginning(int data)
{
    Node *newnode =new Node;
    newnode->data = data;
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}

void SinglyLinkedList::InsertAtEnd(int data)
{
    Node *newnode = new Node;
    newnode->data = data;
    
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void SinglyLinkedList::Reverse()
{
    Node *temp1 = head;
    Node *temp2 = NULL;
    Node *temp3 = NULL;
    while(temp1){
        temp3 = temp2;
        temp2 = temp1;
        temp1 = temp1->next;
        temp2->next = temp3;
    }
    head = temp2;
}

void SinglyLinkedList::Delete(int pos){
    if (pos < 1 || pos > Length())
    {
        return;
    }
    else
    {
        Node *temp;
        Node *del;
        temp = head;
        for (int i = 0; i < pos - 2; i++)
        {
            temp = temp->next;
        }
        del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

}

int main()
{
    int arr[]={1,2,3,4,5};
    int size=5;
    SinglyLinkedList l1(arr,size);
    l1.Display();
    cout<<l1.Length()<<endl;

    l1.Insert(7,5);
    l1.Display();
    cout<<l1.Length()<<endl;
    cout<<l1.DetectCycle()<<endl;
    // l1.InsertAtBeginning(0);
    // l1.InsertAtEnd(6);
    // l1.Display();
    // l1.Reverse();
    // l1.Display();
    // l1.Delete(3);
    // l1.Display();
    return 0;
}