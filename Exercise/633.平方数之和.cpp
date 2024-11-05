/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */
#include <vector>
#include <math.h>
#include <iostream>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            double b = sqrt(c - a * a);
            if (b == int(b)) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end


int main() {
    int c = 5;
    Solution So;

    So.judgeSquareSum(c);
}
