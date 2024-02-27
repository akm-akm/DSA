/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<char, int> r, c;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                if (r.count(board[i][j]) == 0)
                    r[board[i][j]]++;
                else
                    return false;
            }
            r.clear();
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] == '.')
                    continue;
                if (c.count(board[j][i]) == 0)
                    c[board[j][i]]++;
                else
                    return false;
            }
            c.clear();
        }
        for (int i = 0; i < 9; i++)
        {
            if (i % 3 == 0)
                r.clear();
            for (int j = 0; j < 3; j++)
            {
                if (board[j][i] == '.')
                    continue;
                if (r.count(board[j][i]) == 0)
                    r[board[j][i]]++;
                else
                    return false;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            if (i % 3 == 0)
                r.clear();
            for (int j = 6; j < 9; j++)
            {
                if (board[j][i] == '.')
                    continue;
                if (r.count(board[j][i]) == 0)
                    r[board[j][i]]++;
                else
                    return false;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            if (i % 3 == 0)
                r.clear();
            for (int j = 3; j < 6; j++)
            {
                if (board[j][i] == '.')
                    continue;
                if (r.count(board[j][i]) == 0)
                    r[board[j][i]]++;
                else
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

int main()
{
    vector<vector<char>> sudoku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution sol;
    cout << sol.isValidSudoku(sudoku) << endl;
}