/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int max_ = 0, max_temp = 0;
        int num_l = 0;
        int num_r = 0;

        int last_er = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                num_l++;
            } else if (s[i] == ')') {
                num_r++;
            }

            if (num_l < num_r) {
                max_ = max(max_, max_temp);
                last_er = i;
                max_temp = num_l = num_r = 0;
            } else if (num_l == num_r) {
                max_temp++;
                max_ = max(max_, max_temp);
            } else {
                max_temp++;
            }
        }

        if (num_l != num_r) {
            max_temp = num_l = num_r = 0;
            for (int i = s.length() - 1; i >= last_er; i--) {
                if (s[i] == '(') {
                    num_l++;
                } else if (s[i] == ')') {
                    num_r++;
                }

                if (num_l > num_r) {
                    max_ = max(max_, max_temp);
                    // last_er = i;
                    max_temp = num_l = num_r = 0;
                } else {
                    max_temp++;
                }
            }
        } else {
            max_ = max(max_, max_temp);
        }

        return max_;
    }
};
// @lc code=end

