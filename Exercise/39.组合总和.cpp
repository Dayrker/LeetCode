/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
    int tar;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> out;
        sort(candidates.begin(), candidates.end());
        tar = target;
        
        GetZuhes(out, candidates, vector<int>(), 0, 0);
        return out;
    }

    void GetZuhes(vector<vector<int>> & o, vector<int> & c, vector<int> temp, int index, int temp_sum) {
        if (temp_sum == tar) {
            o.push_back(temp);
            return;
        } else if (temp_sum + c[0] > tar) {
            return;
        }

        for (int i = index; i < c.size() && tar - temp_sum >= c[i]; i++) {
            vector<int> tp = temp;
            tp.push_back(c[i]);
            GetZuhes(o, c, tp, i, temp_sum + c[i]);
        }
    }
};
// @lc code=end

