#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        sort(prices.begin(), prices.end());
        int sum = prices[0] + prices[1];
        sum = money - sum;
        if (sum >= 0)
            return sum;
        else
            return money;
    }
};

int main()
{
    Solution sol;
    vector<int> x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
    cout << sol.buyChoco(x, 3);
}
