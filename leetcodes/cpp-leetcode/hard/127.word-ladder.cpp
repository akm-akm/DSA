/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Hard (38.45%)
 * Likes:    11593
 * Dislikes: 1844
 * Total Accepted:    1M
 * Total Submissions: 2.6M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * A transformation sequence from word beginWord to word endWord using a
 * dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... ->
 * sk such that:
 *
 *
 * Every adjacent pair of words differs by a single letter.
 * Every si for 1 <= i <= k is in wordList. Note that beginWord does not need
 * to be in wordList.
 * sk == endWord
 *
 *
 * Given two words, beginWord and endWord, and a dictionary wordList, return
 * the number of words in the shortest transformation sequence from beginWord
 * to endWord, or 0 if no such sequence exists.
 *
 *
 * Example 1:
 *
 *
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 * Output: 5
 * Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot"
 * -> "dog" -> cog", which is 5 words long.
 *
 *
 * Example 2:
 *
 *
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 * Output: 0
 * Explanation: The endWord "cog" is not in wordList, therefore there is no
 * valid transformation sequence.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= beginWord.length <= 10
 * endWord.length == beginWord.length
 * 1 <= wordList.length <= 5000
 * wordList[i].length == beginWord.length
 * beginWord, endWord, and wordList[i] consist of lowercase English
 * letters.
 * beginWord != endWord
 * All the words in wordList are unique.
 *
 *
 */
#include <iostream>
#include <stack>
using namespace std;
// @lc code=start
class Solution
{

public:
    bool isOneChange(string a, string b)
    {
        if (a == b)
            return false;
        int t = 0;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] != b[i])
            {
                t++;
                if (t > 1)
                    return false;
            }
        }
        return true;
    }
    int ll(vector<string> &wordList, string word, string endWord, string prevWord, int l = 0)
    {
        //  cout << word << " ";
        if (l != 0 && !isOneChange(word, prevWord))
        {
            cout << prevWord << " returning-- " << word << endl;
            return -1;
        }
        if (word == endWord)
        {
            cout << "found  " << l;
            return l;
        }
        int m = INT32_MIN;
        for (auto x : wordList)
        {
            // cout << x << " ";

            m = max(m, ll(wordList, x, endWord, word, l + 1));
        }
        return m;
    }
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        return ll(wordList, beginWord, endWord, beginWord);
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<string> v = {"hot", "dot", "dog", "mog", "lot", "log", "cog"};
    cout << sol.ladderLength("hit", "cog", v) << endl;
}