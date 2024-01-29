#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;
template <typename T>
class AdjList
{
public:
    unordered_map<T, list<T>> adjList;
    // vector<int> vertices;
    void addEdge(T u, T v, bool directed)
    {
        // directed == 0 -> undirected graph and directed == 1 -> directed graph;
        // adding edge from u to v
        adjList[u].push_back(v);
        if (!directed)
        {
            adjList[v].push_back(u);
        }
    }
    void display()
    {
        cout << "Vertex -> Linked Vetices" << endl;
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    // int v;
    int e;
    cout << "Enter the no. of  edges : ";
    cin >> e;
    // cout << "Enter the no. of  edges : ";
    // cin >> v;
    AdjList<int> adjl;
    // cout << "Enter Vertices : " << endl;
    // for (int i = 0; i < v; i++)
    // {
    //     int vt;
    //     cin >> vt;
    //     adjl.vertices.push_back(vt);
    // }
    cout << "Enter the vertices who have egde between them (v1 v2) : " << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adjl.addEdge(u, v, 0);
    }
    adjl.display();
    return 0;
}