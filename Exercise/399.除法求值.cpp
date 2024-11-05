/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
private:
    class UnionFind {
    private:
        vector<int> parent;
        vector<double> weight;
    public:
        UnionFind(int n) {  // 构造函数
            parent = vector<int>(n, 0);
            weight = vector<double>(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                weight[i] = 1.0;
            }
        }

        void Union(int x, int y, double value) {
            // 将两团x和联接起来。
            // x的根节点->y的根节点，value为x->y的值。
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) {   return; }

            parent[rootX] = rootY;
            weight[rootX] = weight[y] * value / weight[x];
        }

        /* 路径压缩
        * @param x
        * @return 根节点的id
        */
        int find(int x) {
            if (x != parent[x]) {
                int origin = parent[x];
                parent[x] = find(parent[x]);
                weight[x] *= weight[origin];
            }
            return parent[x];
        }

        double isConnected(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) {
                return weight[x] / weight[y];
            } else {
                return -1.0;
            }
        }
    };
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int equationsSize = equations.size();
        UnionFind unionFind(2 * equationsSize);
        // 第 1 步：预处理，将变量的值与 id 进行映射，使得并查集的底层使用数组实现，方便编码
        unordered_map<string, int> s2id;

        int id = 0;
        for (int i = 0; i < equationsSize; i++) {
            string s1 = equations[i][0];
            string s2 = equations[i][1];
            if (s2id.find(s1) == s2id.end()) {
                s2id[s1] = id++;
            }
            if (s2id.find(s2) == s2id.end()) {
                s2id[s2] = id++;
            }
            unionFind.Union(s2id[s1], s2id[s2], values[i]);
        }

        // 第 2 步：做查询
        int queriesSize = queries.size();
        vector<double> out(queriesSize, 0.0);
        for (int i = 0; i < queriesSize; i++) {
            string s1 = queries[i][0];
            string s2 = queries[i][1];

            if (s2id.find(s1) == s2id.end() || s2id.find(s2) == s2id.end()) {
                out[i] = -1.0;
            } else {
                int id1 = s2id[s1];
                int id2 = s2id[s2];
                out[i] = unionFind.isConnected(id1, id2);
            }
        }

        return out;
    }
};
// @lc code=end

