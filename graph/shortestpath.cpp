#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void path(vector<int> adj[], int s, int v)
{
    queue<int> q;
    int path[v];
    bool vis[v];
    for (int i = 0; i < v; i++)
    {
        vis[i] = false;
        path[i] = INT16_MAX;
    }
    q.push(s);
    path[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto x : adj[u])
        {
            if (!vis[u])
            {
                path[x] = path[u] + 1;
                vis[x] = true;
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        cout << path[i] << " ";
    }
}