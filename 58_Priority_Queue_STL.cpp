#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // max heap
    priority_queue<int> max_heap;
    max_heap.push(4);
    max_heap.push(3);
    max_heap.push(1);
    max_heap.push(2);
    max_heap.push(5);
    priority_queue<int> temp = max_heap;
    cout << "MAX heap :" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // min heap
    priority_queue<int, vector<int>, greater<int>> min_heap;

    min_heap.push(4);
    min_heap.push(3);
    min_heap.push(1);
    min_heap.push(2);
    min_heap.push(5);
    priority_queue<int, vector<int>, greater<int>> tmp = min_heap;
    cout << "MIN heap :" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << tmp.top() << " ";
        tmp.pop();
    }

    return 0;
}