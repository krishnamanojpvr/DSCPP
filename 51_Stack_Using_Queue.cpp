#include <iostream>
#include <queue>
using namespace std;
queue<int> q1;
void push(int val)
{
    q1.push(val);
}
void pop()
{
    if(q1.empty()){
        cout<<"Unable to pop as Stack is UnderFlow"<<endl;
        return;
    }
    int size = q1.size();
    for (int i = 0; i < size - 1; ++i)
    {
        int front = q1.front();
        q1.pop();
        q1.push(front);
    }
    q1.pop();
}
void display()
{
    if(q1.empty()){
        cout<<"Unable to display as stack is underflow"<<endl;
        return;
    }
    int size = q1.size();
    while (size >= 0)
    {
        int i=0;
        while (i < q1.size())
        {
            int front = q1.front();
            if (i == size - 1)
            {
                cout << front << " ";
            }
            q1.pop();
            q1.push(front);
            i++;
        }
        size--;
    }
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();
    cout << endl;

    pop();
    display();
    cout << endl;

    pop();
    display();
    cout << endl;

    pop();
    display();
    cout << endl;

    pop();
    display();
    cout << endl;

    return 0;
}