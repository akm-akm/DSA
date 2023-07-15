#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int size = nums.size() - 1;
        int high = size;
        int low = 0, mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (target == nums[mid])
                return mid;
            if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
};