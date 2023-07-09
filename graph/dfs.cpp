#include <iostream>
#include <vector>

using namespace std;

bool dfsRec(vector<int> adj[], int s, bool visited[], int par)
{
    visited[s] = true;
    for (int x : adj[s])
    {
        if (!visited[x])
            dfsRec(adj, x, visited, s);
        else if (x != par)
            return true;
    }
    return false;
}

bool dfs(vector<int> adj[], int n, int s)
{
    bool visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            if (dfsRec(adj, i, visited, i))
                return true;
    }
    return false;
}

int main()
{
    return 0;
}
