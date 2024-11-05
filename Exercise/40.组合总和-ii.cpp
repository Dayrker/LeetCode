/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
    int tar;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> out;
        sort(candidates.begin(), candidates.end());
        tar = target;
        
        GetZuhes(out, candidates, vector<int>(), -1, 0);
        return out;
    }

    void GetZuhes(vector<vector<int>> & o, vector<int> & c, vector<int> temp, int index, int temp_sum) {
        if (temp_sum == tar) {
            o.push_back(temp);
            return;
        } else if (temp_sum + c[0] > tar) {
            return;
        }

        for (int i = index + 1; i < c.size() && tar - temp_sum >= c[i]; i++) {
            if (i > index + 1 && c[i] == c[i - 1]) {
                continue;
            }

            vector<int> tp = temp;
            tp.push_back(c[i]);
            GetZuhes(o, c, tp, i, temp_sum + c[i]);
        }
    }
};
// @lc code=end

