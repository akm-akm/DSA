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

int prim(vector<int> graph[], int v)
{
    bool mst[v] = {false};
    int res = 0, key[v] = {INT32_MAX};
    key[0] = res = 0;

    for (int i = 0; i < v; i++)
    {
        int u = -1;
        for (int j = 0; j < v; j++)
        {
            if (!mst[j] && (u == -1 || key[j] < key[u]))
            {
                u = i;
            }
        }
        mst[u] = true;
        res = res + key[u];
        for (int i = 0; i < v; i++)
        {
            
        }
    }
}

int main()
{
    return 0;
}