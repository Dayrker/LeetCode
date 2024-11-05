/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

public:
    void dfs(int u) {
        if (!valid) {   // 若已有环，直接退出即可
            return;
        }
        visited[u] = 1;
        for (int v: edges[u]) {
            if (visited[v] == 0) {  // 若是没去过，则继续遍历邻居节点
                dfs(v);
            } else if (visited[v] == 1) {   // 若是去过，则有环，直接退出
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]); // 构建结点info[1]的邻居
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return valid;
    }
};
// @lc code=end

