#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 1 - -1

// 2 - 2
// 3 - 3

// 4 - 2,2
// 5 - 3,2
// 6 - 3,3
// 7 - 3,2,2
// 8 - 3,3,2
// 9 - 3,3,3

// 10- 3,3,2,2

int main()
{
    vector<int> as = {2, 1, 2, 2, 3, 3};
    unordered_map<int, int> map;
    int count = 0;
    for (int i : as)
        map[i]++;

    unordered_map<int, int>::iterator it = map.begin();
    while (it != map.end())
    {
        if (it->second == 1)
        {
            count = -1;
            break;
        }
        count += it->second / 3;
        if (it->second % 3 != 0)
            count += 1;
        ++it;
    }
    cout << count << endl;
    return 0;
}