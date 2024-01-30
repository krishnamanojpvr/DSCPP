#include <iostream>
using namespace std;
int vertarr[20][20];
int count = 0;
void displayMatrix(int v)
{
    int i, j;
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            cout << vertarr[i][j] << " ";
        }
        cout << endl;
    }
}
void add_edge(int u, int v)
{
    vertarr[u][v] = 1;
    vertarr[v][u] = 1;
}
int main()
{
    int v = 2;
    add_edge(0, 1);
    add_edge(1, 0);
    displayMatrix(v);
}
