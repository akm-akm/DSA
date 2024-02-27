/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.33%)
 * Likes:    23006
 * Dislikes: 1609
 * Total Accepted:    4.1M
 * Total Submissions: 10.2M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Every close bracket has a corresponding open bracket of the same type.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(]"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 *
 *
 */
#include <iostream>
#include <string>
#include <stack>

using namespace std;
// @lc code=start
class Solution
{
private:
    bool match(char a, char b)
    {
        return ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'));
    }

public:
    bool isValid(string a)
    {
        stack<char> s;

        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == '(' || a[i] == '{' || a[i] == '[')
            {
                s.push(a[i]);
            }
            else
            {
                if (s.empty())
                    return false;
                else if (!match(s.top(), a[i]))
                    return false;
                else
                    s.pop();
            }
        }
        return s.empty();
    }
};
// @lc code=end
int main()
{
    Solution sol;
    cout << sol.isValid("[](){w}") << endl;
}
