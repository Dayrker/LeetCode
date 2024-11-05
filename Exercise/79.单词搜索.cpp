/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
    int m, n;
    string w;
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        w = word;
        vector<vector<int>> Comed(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(dfs(board, i, j, 0, Comed)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> & b, int i, int j, int index, vector<vector<int>> & C)
    {   
        if (i < 0 || j < 0 || i >= m || j >= n || C[i][j] == 1 || b[i][j] != w[index]) {
            return false;
        }

        // 记录走过的地方，和匹配成功的字符个数
        C[i][j] = 1;
        index++;    // 匹配成功，记录成功的字符个数

        if (index == w.length()) {  // 成功字符个数达到w_len的时候，匹配成功
            return true;
        }
        
        bool result = dfs(b, i + 1, j, index, C) || dfs(b, i, j + 1, index, C) || dfs(b, i - 1, j, index, C) || dfs(b, i, j - 1, index, C);
        C[i][j] = 0;
        return result;
    }
};
// @lc code=end

