#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next = NULL;
    Node *prev = NULL;
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList();
    DoublyLinkedList(int data);
    // ~DoublyLinkedList();
    void Display();
    void Insert(int data, int pos);
    void Delete(int pos);
    void Reverse();
    int Length();
    void InsertAtBeginning(int data);
    void InsertAtEnd(int data);
};

DoublyLinkedList::DoublyLinkedList()
{
    head = NULL;
    tail = NULL;
}

DoublyLinkedList::DoublyLinkedList(int data)
{
    Node *newnode = new Node;
    newnode->data = data;

    head = newnode;
    tail = newnode;
}

void DoublyLinkedList::Display()
{
    Node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << "<=>";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

int DoublyLinkedList::Length()
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void DoublyLinkedList::Insert(int data, int pos)
{
    if (pos < 1 || pos > Length()+1)
    {
        cout << "Position is Out of List";
        return;
    }
    else if (pos == 1)
    {
        InsertAtBeginning(data);
        return;
    }
    else if (pos == Length()+1)
    {
        InsertAtEnd(data);
        return;
    }
    Node *temp, *newnode;
    temp = head;
    newnode = new Node;
    newnode->data = data;
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->prev = temp->next->prev;
    temp->next = newnode;
    newnode->next->prev = newnode->prev;
}

void DoublyLinkedList::Delete(int pos){
     if (pos < 1 || pos > Length())
    {
        cout<<"Position Out of List";
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
        temp->next = del->next;
        del->next->prev = del->prev;
        del->next = NULL;
        del->prev = NULL;
        delete del;
    }
}

void DoublyLinkedList::InsertAtBeginning(int data)
{
    Node *newnode = new Node;
    newnode->data = data;
    newnode->next = head;
    head->prev = newnode;
    tail = head;
    head = newnode;
}

void DoublyLinkedList::InsertAtEnd(int data)
{
    Node *newnode = new Node;
    newnode->data = data;
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
    return;
}


int main()
{
    DoublyLinkedList l1(10);
    l1.Display();
    cout << l1.Length()<<endl;

    l1.InsertAtBeginning(90);
    l1.Display();
    cout << l1.Length()<<endl;

    l1.InsertAtEnd(30);
    l1.Display();
    cout<<l1.Length()<<endl;

    l1.Insert(50 , 3);
    l1.Display();
    cout<<l1.Length()<<endl;

    l1.Delete(3);
    l1.Display();
    cout<<l1.Length()<<endl;

}





