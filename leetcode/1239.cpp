#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int m = -1;
    bool checkDuplicateChar(string &current, string &next)
    {
        //  cout << current << " - " << next << endl;
        for (int i = 0; i < next.length(); i++)
        {
            if (current.find(next[i]) != string::npos)
                return true;
        }
        return true;
    }

public:
    int maxLength(vector<string> &arr, string s = "", int k = 0)
    {
        if (k == arr.size())
        {
            //  cout << s << endl;
            return s.length();
        }
        for (int i = k; i < arr.size(); i++)
        {
            bool is_dup = checkDuplicateChar(s, arr[i]);
            // cout << is_dup << endl;
            if (is_dup)
            {
                s = s.append(arr[i]);
                cout << s;
                m = max(m, maxLength(arr, s, i + 1));
            }
        }
        return m;
    }
};

int main()
{
    Solution sol;
    vector<string> a = {"cha", "r", "act", "ers"};
    cout << sol.maxLength(a) << endl;
}
