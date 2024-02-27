#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int hour(int m, vector<int> v)
{
    long s = 0;
    for (double x : v)
    {
        int h = ceil(x / m);
        if (h == 0)
        {
            h = 1;
        }
        cout << h << " ";
        s += h;
    }
    cout << endl;
    return s;
}

int minimumRateToEatBananas(vector<int> v, int h)
{
    int low = 1;
    int ans;
    int high = INT_MIN;
    for (int l : v)
    {
        ans = high = max(high, l);
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        long hou = hour(mid, v);
        if (hou <= h)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = 1 + mid;
        }
    }

    return ans;
}

int main()
{
    vector<int> p = {805306368, 805306368, 805306368};
    int b = minimumRateToEatBananas(p, 1000000000);
    cout << b << endl;
    return 0;
}