/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int preMin = prices[0];
        int maxP = 0, tempP = 0;
        for (int i = 1 ; i < prices.size(); i++) {
            tempP = prices[i] - preMin;
            maxP = tempP > maxP ? tempP : maxP;
            preMin = min(preMin, prices[i]);
        }
        return maxP;
    }
};
// @lc code=end

