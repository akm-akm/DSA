#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool cycle(vector<int> adj[], int v)
{
    queue<int> q;
    int c = 0;
    int indegree[v];
    for (int i = 0; i < v; i++)
    {
        indegree[i] = 0;
    }
    for (int i = 0; i < v; i++)
    {
        for (int x : adj[i])
        {
            indegree[x]++;
        }
    }
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] = 0)
            q.push(i);
    }
    while (!q.empty())
    {

        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto x : adj[u])
        {
            indegree[x]--;
            if (indegree[x] == 0)
                q.push(x);
        }
        c++;
    }
    if (c != v)
    {
        return true;
    }
}
int main()
{
    return 0;
}