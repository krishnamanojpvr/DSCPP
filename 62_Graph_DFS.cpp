#include <iostream>
using namespace std;
#include <unordered_map>
#include <algorithm>
#include <list>
#include <vector>
#include <stack>
// template <typename int>
class GraphDFS
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

    // DFS using STACK
    void DFS(int vertex, unordered_map<int, bool> &visited)
    {
        stack<int> st;
        if (!visited[vertex])
        {
            st.push(vertex);
            visited[vertex] = true;
        }
        while (!st.empty())
        {
            int top = st.top();
            cout << top << " ";
            st.pop();
            for (auto i : adjList[top])
            {
                if (!visited[i])
                {
                    st.push(i);
                    visited[i] = true;
                }
            }
        }
    }


    // DFS using RECURSION
    // void DFS(int vertex, unordered_map<int, bool> &visited)
    // {

    //     if (!visited[vertex])
    //     {
    //         cout<<vertex<<" ";
    //         visited[vertex] = true;
    //     }

    //         for (auto i : adjList[vertex])
    //         {
    //             if (!visited[i])
    //             {
    //                 DFS(i,visited);
    //             }
    //         }
    // }

    void display()
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
    GraphDFS g;
    g.addEdge(0, 3, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 4, 0);
    g.addEdge(5, -1, 0); // for isolated vertex
    unordered_map<int, bool> visited;
    for (int i = 0; i < g.vertices.size(); i++)
    {
        visited[g.vertices[i]] = false;
    }
    cout << "DFS" << endl;
    for (int i = 0; i < g.vertices.size(); i++)
    { // this loop is used in case if graph is disconnected.
        g.DFS(g.vertices[i], visited);
    }
    // g.display();
    return 0;
}