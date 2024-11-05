/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
    int nums;
public:
    vector<string> generateParenthesis(int n) {
        nums = n;
        // stack<char> l_brackets;
        // stack<char> r_brackets;
        // for (int i = 0 ; i < n; i++) {
        //     l_brackets.push('(');
        //     r_brackets.push(')');
        // }
        vector<string> out;
        string s;
        generate(out, s);

        return out;
    }

    void generate(vector<string> & bs, string s, int l = 0, int r = 0) {
        if (l == nums && r == nums) {
            bs.push_back(s);
            return;
        }

        if (l == r) {
            generate(bs, s + '(', l + 1, r);
        } else if (l > r) {
            if (l == nums) {
                generate(bs, s + ')', l, r + 1);
            } else {
                generate(bs, s + '(', l + 1, r);
                generate(bs, s + ')', l, r + 1);
            }
        } 
    }
};
// @lc code=end

