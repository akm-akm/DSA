#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 2, 1};
    int maxi = INT8_MIN;
    int maxAns = 0;
    int maxFreq = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < 4; i++)
    {
        m[arr[i]]++;
        maxFreq = max(m[arr[i]], maxFreq);
    }
    for (auto x : arr)
    {
        if (maxFreq == m[arr[x]])
        {
            maxAns = x;
            break;
        }
    }
    cout << maxAns << endl;
    return 0;
}