#include <iostream>
#include <vector>

using namespace std;

bool cyycleRec(vector<int> adj[], bool recSt[], bool vis[], int s)
{
    vis[s] = true;
    recSt[s] = true;
    for (auto x : adj[s])
    {
        if (!vis[x] && cyycleRec(adj, recSt, vis, x))
            return true;
        else if (vis[x])
            return true;
        recSt[s] = false;
        return false;
    }
}

bool cycle(vector<int> adj[], int v)
{
    bool recSt[v], vis[v];
    for (int i = 0; i < v; i++)
    {
        recSt[i] = vis[i] = false;
    }

    vis[0] = true;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            if (cyycleRec(adj, recSt, vis, i))
                return true;
    }
}