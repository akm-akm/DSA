#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numWays(int steps, int arrLen, int curr_index = 0, int s = 0)
    {
        if ((s == steps && curr_index != 0) || curr_index == arrLen)
            return 0;
        if (curr_index == 0 && s == steps)
            return 1;
        int l = 0, r = 0, st;
        st = numWays(steps, arrLen, curr_index, s + 1);
        if (curr_index <= steps - s)
            r = numWays(steps, arrLen, curr_index + 1, s + 1);
        if (curr_index > 0)
            l = numWays(steps, arrLen, curr_index - 1, s + 1);
        return l + st + r;
    }
};

int main()
{
    Solution sol;
    cout << sol.numWays(27, 7) << endl;
}