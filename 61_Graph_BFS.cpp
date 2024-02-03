#include <iostream>
using namespace std;
#include <unordered_map>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
// template <typename int>
class GraphBFS
{
public:
    unordered_map<int, list<int>> adjList;
    vector<int> vertices;
    void addEdge(int u, int v, bool directed)
    {
        if (v != -1)
        {
            adjList[u].push_back(v);
            if (!directed)
            {
                adjList[v].push_back(u);
            }
            if (vertex_check(u))
            {
                vertices.push_back(u);
            }
        }
        else
        {
            adjList[u];
            if (vertex_check(u))
            {
                vertices.push_back(u);
            }
        }
    }

    bool vertex_check(int v)
    {
        auto vert = find(vertices.begin(), vertices.end(), v);
        if (vert != vertices.end())
        {
            return false;
        }
        return true;
    }

    void BFS(int vertex, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        if (!visited[vertex])
        {
            q.push(vertex);
            visited[vertex] = true;
        }
        while (!q.empty())
        {
            int front = q.front();
            cout << front << " ";
            q.pop();
            for (auto i : adjList[front])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    void displayAdjList()
    {
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
    GraphBFS g;
    g.addEdge(0, 3, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 4, 0);
    g.addEdge(5, -1, 0);
    unordered_map<int, bool> visited;
    for (int i = 0; i < g.vertices.size(); i++)
    {
        visited[g.vertices[i]] = false;
    }
    cout << "BFS" << endl;
    for (int i = 0; i < g.vertices.size(); i++)
    { // this loop is used in case if graph is disconnected.
        g.BFS(g.vertices[i], visited);
    }
    // g.displayAdjList();
    return 0;
}