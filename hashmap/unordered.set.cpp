#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> s;
    for (int i = 0; i < 6; i++)
    {
        s.insert(i);
    }
    for (auto x : s)
    {
        cout << x << " ";
    }
    unordered_set<int>::iterator it = s.begin();

    for (it; it != s.end(); it++)
    {
        cout << *it << " ";
    }

    cout << s.size();
    //  s.clear();
    cout << s.size() << endl;

    if (s.find(2) != s.end())
    {
        cout << *s.find(2);
    }
    else
    {
        cout << "Not Found";
    }
    s.erase(4);
    s.erase(s.begin(), s.end());

    if (s.count(5))
    {
        cout << "Found";
    }
    else
    {
        cout << "Not Found";
    }
    return 0;
}