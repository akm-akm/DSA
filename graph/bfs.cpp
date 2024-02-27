#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void printGraph(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int x : adj[i])
            cout << x << " ";
        cout << endl;
    }
}
void addGraph(vector<int> adj[], int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}
void bfs(vector<int> adj[], int s, int v)
{
    queue<int> q;
    bool visited[v + 1];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    q.push(0);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        cout << q.front();
        q.pop();
        for (auto x : adj[u])
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
    }
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
