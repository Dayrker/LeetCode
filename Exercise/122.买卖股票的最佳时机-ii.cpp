/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        int maxP = 0, tempP = 0;

        for (int i = 1; i < days; i++) {
            tempP = prices[i] - prices[i - 1];
            if (tempP > 0) {
                maxP += tempP;
            }
        }
        return maxP;
    }
};
// @lc code=end

