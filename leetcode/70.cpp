#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, int> memo;
    memo[0] = 1;
    int n = 45;
    for (int i = 1; i <= n; i++)
    {
        memo[i] = 0;
        for (int j = 1; j <= 2; j++)
        {
            int subproblem = i - j;
            if (subproblem < 0)
                continue;
            memo[i] = memo[i] + memo[subproblem];
        }
    }
    cout << memo[n]<<endl;
    return 0;
}