/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool isSafe(string a, int b)
    {
        if (abs((a[a.length() - 1] - '0') - b) <= 1)
            return false;
        else if (a.find(to_string(b)) != string::npos)
            return false;
        return true;
    }
    vector<string> draw(string a, int n)
    {
        vector<string> a;
        string row = ".";
        for (int i = 1; i < n; i++)
        {
            row = row + ".";
        }
        for (int i = 1; i < n; i++)
        {
            a.push_back('row');
        }
        for (int i = 0; i < a.length(); i++)
        {
            string temp = row;
            temp[a[a[i]] - '0'] = 'Q';
            a.push_back(temp);
        }
        reverse(a.begin(), a.end());
    }
    void solve(int n, string q = "")
    {
        if (q.length() == n)
        {
            cout << q << endl;
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (q.length() != 0 && !isSafe(q, i))
            {
                //  cout << "cut: " << q << i << endl;
                continue;
            }

            solve(n, q + to_string(i));
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        return a;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<vector<string>> v;
    //  v = sol.solveNQueens(5);
    sol.solve(10);
}