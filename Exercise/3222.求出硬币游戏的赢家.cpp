/*
 * @lc app=leetcode.cn id=3222 lang=cpp
 *
 * [3222] 求出硬币游戏的赢家
 */
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    string losingPlayer(int x, int y) {
        // 75: x个， 10: y个
        // 0 <= coinX <= x, 0 <= coinY <= y
        // total: 115 = coinX * 75 + coinY * 10
        // coinX = 1, coinY = 4

        // // 解法1，遍历
        // int coinX = 1;
        // int coinY = 4;
        // int used_coinX = coinX;
        // int used_coinY = coinY;

        // int winner = 1;
        // while (used_coinX <= x && used_coinY <= y) {
        //     used_coinX += coinX;
        //     used_coinY += coinY;
        //     winner = winner * (-1);
        // }
        // if (winner == 1)
        //     return "Bob";
        // else
        //     return "Alice";
        
        // 解法2，结束状态
        int y_count = y / 4;
        int y_remain = y % 4;

        return (min(x, y_count) % 2 == 1) ? "Alice": "Bob";

    }
};
// @lc code=end

