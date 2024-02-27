#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void sort(vector<int> adj[], int v, int a[]){
    int c = 0;
    queue<int> q;
    int indegree[v];
    for (int i = 0; i < v; i++)
        indegree[i] = 0;
    for (int i = 0; i < v; i++)
        for (int x : adj[i])
            indegree[x]++;
    for (int i = 0; i < v; i++)
        if (indegree[i] == 0)
            q.push(i);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        a[c] = u;
        c++;
        for (auto x : adj[u])
        {
            indegree[x]--;
            if (indegree[x] == 0)
                q.push(x);
        }
    }
}
int weight(int x, int y){
    return x + y;}
void shortestPath(vector<int> adj[], int v, int s){
    int a[v], dist[v];
    for (int i = 0; i < v; i++)
        dist[i] = INT32_MAX;
    dist[s] = 0;
    sort(adj, v, a);
    for (int i = 0; i < v; i++)
        for (auto x : adj[i])
            if (dist[x] > dist[x] + weight(i, x))
                dist[x] = dist[x] + weight(i, x);
    for (int i = 0; i < v; i++)
        cout << dist[i] << " ";
}

int main(){
    return 0;}