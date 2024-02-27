/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;
// @lc code=start
class Solution
{
private:
    int t = 0, v = 0, w = 0;
    bool isValidSudoku(vector<vector<char>> &board, int i, int j, int k)
    {

        board[i][j] = k + '0';
        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> col(9, vector<int>(9, 0));
        vector<vector<int>> mat(9, vector<int>(9, 0));

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.' && (row[i][board[i][j] - '1'] == 1 || col[j][board[i][j] - '1'] == 1))
                    return false;

                if (board[i][j] != '.')
                {
                    row[i][board[i][j] - '1'] = 1;
                    col[j][board[i][j] - '1'] = 1;
                }

                int r = 3 * (i / 3) + (j / 3);
                if (board[i][j] != '.' && mat[r][board[i][j] - '1'] == 1)
                {
                    return false;
                }

                if (board[i][j] != '.')
                {
                    mat[r][board[i][j] - '1'] = 1;
                }
            }
        }
        return true;
    }
    void print(vector<vector<char>> &sudoku, int l = 0)
    {
        for (auto x : sudoku)
        {
            for (auto a : x)
            {
                cout << a;
            }
            cout << endl;
        }
    }
    void printSudoku(vector<vector<char>> &sudoku, int l)
    {
        cout << l << " " << t << " " << v << " " << w << endl;
        cout << "|-------+-------+-------|\n";

        for (int i = 0; i < 9; ++i)
        {
            if (i % 3 == 0 && i != 0)
            {
                cout << "|-------+-------+-------|\n";
            }
            cout << "| ";

            for (int j = 0; j < 9; ++j)
            {
                if (j % 3 == 0 && j != 0)
                {
                    cout << "| ";
                }
                cout << sudoku[i][j] << ' ';
            }
            cout << "| ";

            cout << endl;
        }
        cout << "|-------+-------+-------|\n"
             << endl;
    }

public:
    void solveSudoku(vector<vector<char>> board)
    {
        int res = 0, *t = 0;
        for (auto x : board)
        {
            for (auto a : x)
            {
                if (a == '.')
                    res++;
            }
        }
        try
        {
            solve(board, res);
        }
        catch (invalid_argument &e)
        {
        }
    }

    void solve(vector<vector<char>> board, int l)
    {
        // cout << endl;
        printSudoku(board, l);
        if (l == 0)
        {
            w++;
            throw std::invalid_argument("Found");
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                v++;
                if (board[i][j] != '.')
                    continue;
                for (int k = 1; k <= 9; k++)
                {
                    if (isValidSudoku(board, i, j, k))
                    {
                        t++;
                        board[i][j] = '0' + k;
                        solve(board, l - 1);
                    }
                    else
                        continue;
                }
            }
        }
    }
};
// @lc code=end

int main()
{
    cout << "solving";
    vector<vector<char>> sudoku = {
        {'.', '1', '.', '.', '.', '.', '.', '.', '.'},
        {'9', '.', '2', '.', '6', '.', '1', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '3', '.', '.', '5', '7', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'1', '8', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '7', '.', '.', '.', '3'},
        {'.', '.', '.', '.', '.', '.', '.', '1', '8'}};
    Solution sol;
    sol.solveSudoku(sudoku);
}