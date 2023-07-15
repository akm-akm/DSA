#include <vector>
#include <iostream>
using namespace std;

vector<int> bitManipulation(int num, int i)
{
    int n = 1;
    vector<int> res;

    if (num && (1 << i-1))
    {
        res.push_back(1);
    }
    else
    {
        res.push_back(0);
    }
    res.push_back(num | (1 << i-1));
    res.push_back(num & ~(1 << i-1));
    return res;
}
int main()
{
    vector<int> a = bitManipulation(9,2);
    for (int i = 0; i < 3; i++)
    {
        cout << a[i] << endl;
    }
}