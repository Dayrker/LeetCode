/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> F(amount + 1, amount + 1);
        F[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    F[i] = min(F[i], F[i - coins[j]]);
                }
            }
            F[i] = F[i] + 1;
        }

        return F[amount] > amount ? -1 : F[amount];
    }
};
// @lc code=end

