// This is a ToDoList implemented using MinHeap
// For simplicity, I took the value as a string instead of int because
// there can be a bit of confusion when both priorities and values are integers
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// By default priority queue template is max-heap ; priority_queue<int> pq; For Min Heap, use below;
// priority_queue<int, vector<int>, greater<int>> q;

class Node
{
public:
    string task;
    int priority;

    Node() : task(""), priority(-1) {} // Just a shortcut for the normal constructor
    // Node(){
    //     this->task = "";
    //     this->priority = -1;
    // }

    Node(string task, int priority) : task(task), priority(priority) {} // Just a shortcut for the normal constructor
    // Node(string task, int priority){
    //     this->task = task;
    //     this->priority = priority;
    // }
};

class ToDoList
{
    void minHeapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (arr[index].priority < arr[parent].priority)
            {
                std::swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }
    void minHeapifyDown(int index)
    {
        while (true)
        {
            int smallest = index;
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;

            if (leftChild <= size - 1 && arr[leftChild].priority < arr[smallest].priority)
            {
                smallest = leftChild;
            }
            if (rightChild <= size - 1 && arr[rightChild].priority < arr[smallest].priority)
            {
                smallest = rightChild;
            }

            if (smallest != index)
            {
                std::swap(arr[index], arr[smallest]);
                index = smallest;
            }
            else
            {
                break;
            }
        }
    }

public:
    Node *arr;
    int size;
    int capacity;

    // / ToDoList(int capacity = 10) : capacity(capacity), size(0) {
    // /    arr = new Node[capacity];
    // / } Same as Below One

    ToDoList()
    {
        size = 0;
        capacity = 10;
        arr = new Node[capacity];
    }
    void Insert(string task, int priority)
    {
        Node *newNode = new Node(task, priority);
        if (size == capacity)
        {
            capacity = 2 * capacity;
            Node *newArr = new Node[capacity];
            for (int i = 0; i < size; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[size++] = *newNode;
        minHeapifyUp(size - 1);
    }
    string extractHighestPriority()
    {
        if (size > 0)
        {
            string mini = arr[0].task;
            std::swap(arr[0], arr[size - 1]);
            size--;
            minHeapifyDown(0);
            return mini;
        }
        else
        {
            return "ToDoList Underflow";
        }
    }

    void Display(){
        if(size<1){
            cout << "ToDoList Underflow" << endl;
            return;
        }
        for (int i = 0; i < size; ++i)
        {
            cout << arr[i].priority << " -> " << arr[i].task << endl;
        }
        cout << endl;
        return;
    }
};

int main()
{
    ToDoList tdl;
    int choice = 1;
    while(choice){

        cout<<"Enter Task and Priorty of the element you want to add in the ToDoList : "<<endl;
        string task;
        int priority;
        cout<<"Task : ";
        cin>>task;
        cout<<"Priority : ";
        cin>>priority;
        tdl.Insert(task,priority);
        int ch;
        cout<<"Enter again?(0 to quit) : ";
        cin>>ch;
        choice = ch;
    }

    cout << "ToDoList" << endl;
    tdl.Display();

    cout << "ToDoList after Extracting Highest Priority : " << endl;
    cout<<"Highest Priority Task : "<<tdl.extractHighestPriority()<<endl<<endl;
    tdl.Display();

    tdl.Insert("Youtube",5);
    cout << "ToDoList after adding a task of certain priority : " << endl;
    tdl.Display();

    return 0;
}