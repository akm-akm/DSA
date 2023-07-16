#include <iostream>
#include <vector>

using namespace std;
//  {2, 3, 5, 8, 9, 10}
//                      8
//                    /   \
//                  3      9
//                 / \       \
//                2   5       10
//              / \   /       / \
//             1   4 0       6  14
//
//
// [1,2,4,3,0,5,8,9,6,10,14]

bool valid(int l, int r, int h)
{
    if (l < h && r > h)
        return true;
    return false;
}

bool isValidBST(vector<int> &order)
{
    // Write youherer code .
}
