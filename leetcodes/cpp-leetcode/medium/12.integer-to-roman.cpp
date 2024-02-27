/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */
#include <iostream>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution
{
private:
    string assignNumeral(int num)
    {
        int a[] = {1, 5, 10, 50, 100, 500, 1000};
        unordered_map<int, string> m;
        m[1] = 'I';
        m[5] = 'V';
        m[10] = 'X';
        m[50] = 'L';
        m[100] = 'C';
        m[500] = 'D';
        m[1000] = 'M';
    }

public:
    string intToRoman(int num)
    {
        unordered_map<int, string> m;
        m[1] = 'I';
        m[5] = 'V';
        m[10] = 'X';
        m[50] = 'L';
        m[100] = 'C';
        m[500] = 'D';
        m[1000] = 'M';

        if (m.count(num) >= 1)
            return m[num];
        string s = "";
        int temp = num;
        // 2988
        for (int i = 3; i >= 1; i--)
        {
            int a = temp / pow(10, i);
            if (a != 0)
            {

            }
        }
    }
};
// @lc code=end

int main()
{
    Solution sol;
    cout << sol.intToRoman(89);
}

/*
 * check the next closest big value upto 4000 starting from 3
 * 9 - next big 10.
 * if less by 3
 * 55 - LV
 * 90 - XL
 * 80 - XXL
 *
 */