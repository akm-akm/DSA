/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int temp = 0;
        int sum = 0;
        for (int i = 0; i < height.size(); i++)
        {
            
        }
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 0, 0, 2, 4, 2, 1, 5, 6, 3, 9, 0, 1};
    cout << sol.trap(v);
}