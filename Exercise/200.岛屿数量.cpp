/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
    vector<vector<bool>> visited;
    int M, N;
public:
    void walkIsland(int i, int j, vector<vector<char>>& g) {
        if (i < 0 || j < 0 || i >= M || j >= N || visited[i][j] || g[i][j] == '0') {
            return;
        }
        visited[i][j] = true;
        walkIsland(i, j + 1, g);
        walkIsland(i, j - 1, g);
        walkIsland(i - 1, j, g);
        walkIsland(i + 1, j, g);
    }

    int numIslands(vector<vector<char>>& grid) {
        M = grid.size(), N = grid[0].size();
        visited = vector<vector<bool>>(M, vector<bool>(N, false));

        int numI = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    numI++;
                    walkIsland(i, j, grid);
                }
            }
        }
        return numI;
    }
};
// @lc code=end

