#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    cout<<"okok";
    unordered_map<string, int> m;
    unordered_map<int, int> mp;
    
    pair<string, int> a("hello", 1);
    m.insert(a);
    pair<string, int> p = make_pair("how", 2);
    m.insert(p);
    cout << m.at("hello") << endl;
    cout << m.at("how") << endl;
    m["how"] = 4;
    cout << m.at("how") << endl;

    cout << m["ok"] << endl;
    cout << m.at("ok") << endl;
    for (auto x : m)
    {
        cout << x.first << " " << x.second << endl;
    }
    unordered_map<string, int>::iterator i = m.begin();
    while (i != m.end())
    {
        cout << i->first << i->second << endl;
        i++;
    }

    mp[6]++;
    mp[6]++;
    mp[6]++;
    cout << mp[6] << endl;
    return 0;
}