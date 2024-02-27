#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    vector<string> v;
    void gp(int n, string s = "", int o = 0, int c = 0)
    {
        if (c > o || o > n || c > n)
            return;
        if (o == n && c == n)
        {
            
            v.push_back(s);
            return;
        }
        gp(n, s + "(", o + 1, c);
        gp(n, s + ")", o, c + 1);
    }
    vector<string> generateParenthesis(int n)
    {
        gp(n);
        return v;
    }
};

int main()
{
    Solution sol;
    vector<string> s = sol.generateParenthesis(3);
    for (auto x : s)
    {
        cout << x << endl;
    }
}