#include <iostream>
#include <vector>
using namespace std;

void printGraph(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
void addGraph(vector<int> adj[], int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}
int main()
{
    int v = 4;
    vector<int> adj[v];

    addGraph(adj, 0, 1);
    addGraph(adj, 0, 2);
    addGraph(adj, 1, 2);
    addGraph(adj, 1, 3);
    printGraph(adj, v);
    return 0;
}
