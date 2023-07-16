#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
// GREED = [1, 2, 3], SIZE = [1, 2, 3, 4]

int assignCookie(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end()); // sort the children's greed factors in non-decreasing order
    sort(s.begin(), s.end()); // sort the cookie sizes in non-decreasing order
    int contentChildren = 0;
    int i = 0; // pointer to the current child's greed factor
    int j = 0; // pointer to the current cookie size
    while (i < g.size() && j < s.size())
    {
        if (s[j] >= g[i])
        { // if the current cookie can satisfy the current child's greed factor
            contentChildren++;
            i++;
        }
        j++;
    }
    return contentChildren;
}

int main()
{
    vector<int> GREED;
    vector<int> SIZE;
    int N, M, temp;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        GREED.push_back(temp);
    }
    for (int i = 0; i < M; i++)
    {
        cin >> temp;
        SIZE.push_back(temp);
    }

    cout << assignCookie(GREED, SIZE);
}