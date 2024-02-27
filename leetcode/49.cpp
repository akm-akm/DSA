#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    unordered_map<string, int> m;
    vector<vector<string>> v;
    vector<string> t;
    int c = 0;
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if (m.count(temp) == 0)
            {
                t.push_back(strs[i]);
                v.push_back(t);
                t.clear();
                m[temp] = c;
                c++;
            }
            else
            {
                int x = m.at(temp);
                v[x].push_back(strs[i]);
            }
        }
        return v;
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> xx = sol.groupAnagrams(strs);
}