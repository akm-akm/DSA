#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool cycleRec(vector<int> adj[], int s, bool vis[])
{
    queue<int> q;

    q.push(s);
    vis[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto x : adj[u])
        {
            if (vis[x])
                return true;
        }
    }
    return true;
}

int main()
{
    return 0;
}

bool cycle(vector<int> adj[], int s, int v)
{
    bool vis[v];
    for (int i = 0; i < v; i++)
    {
        vis[i] = false;
    }
    cycleRec(adj, s, vis);
}