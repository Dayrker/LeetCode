/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max1 = 0, max2 = 0;
        int Profit = 0, max1_preMin = 0;
        int preMin = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if (prices[i] >= prices[i - 1]) {
                Profit += prices[i] - prices[i - 1];
            } else {
                max2 = max(max2, max(prices[i - 1] - preMin + max1_preMin, max1 + Profit));
                Profit = 0;
                max1 = max(prices[i - 1] - preMin, max1);
            }

            if (prices[i] < preMin) {
                preMin = prices[i];
                max1_preMin = max1;
            }
        }
        if (Profit > 0) {
            max2 = max(max2, max(prices[prices.size() - 1] - preMin + max1_preMin, max1 + Profit));
        }

        return max2;
    }
};
// @lc code=end

