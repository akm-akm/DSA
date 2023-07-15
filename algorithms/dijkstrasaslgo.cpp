#include <iostream>
#include <vector>

using namespace std;

//     0 1 2 3 4 5 6
// |0| 0 1 3 0 0 1 0
// |1| 0 0 0 7 5 0 3
// |2| 1 0 0 0 2 5 1
// |3| 3 7 0 0 7 0 0
// |4| 0 5 2 7 0 0 8
// |5| 1 0 5 0 0 0 0
// |6| 0 3 1 0 8 0 0

vector<int> dijkstra(int graph[][6], int v, int src)
{
    vector<int> dis(v, INT32_MAX);
    dis[src] = 0;
    vector<bool> fin(v, false);
    for (int i = 0; i < v - 1; i++)
    {
        int u = -1;
        for (int j = 0; j < v; j++)
        {
            if (!fin[j] && dis[j] != INT32_MAX && (u == -1 || dis[j] < dis[u]))
                u = j;
        }
        fin[u] = true;

        for (int k = 0; k < v; k++)
        {
            if (graph[u][k] != 0 && !fin[k])
                dis[k] = min(dis[k], dis[u] + graph[k][u]);
        }
    }
    return dis;
}

int main()
{
    int graph[6][6] = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}};
    vector<int> res = dijkstra(graph, 6, 0);
    for (auto x : res)
    {
        cout << x << " ";
    }
    return 0;
}