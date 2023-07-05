#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

bool isValid(string s)
{
    unordered_map<char, int> m;
    m['{'] = 1;
    m['}'] = 1;
    m['('] = 2;
    m[')'] = 2;
    m['['] = 3;
    m[']'] = 3;
    if (s.size() % 2 != 0)
    {
        return false;
    }
    for (int i = 1; i < s.size(); i += 2)
    {
        if ((m[s[i]] ^ m[s[i - 1]]) != 0)
            return false;
    }
    return true;
}
int main()
{
    cout << isValid("()[]]{}");
}