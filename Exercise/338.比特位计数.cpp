/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */
#include <vector>
#include <math.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> out(n + 1, 0);
        if (n == 0) {   return out; }
        out[1] = 1;
        for (int i = 2; i <= n; i++) {
            int num = i;
            
            int maxBit = int(log(num) / log(2));
            num -= pow(2, maxBit);

            out[i] = out[num] + 1;
        }
        return out;
    }
};
// @lc code=end

