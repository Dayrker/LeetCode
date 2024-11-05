/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include <vector>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s;
        vector<int> out(n, 0);

        for (int i = 0; i < n; i++) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int preIndex = s.top();
                out[preIndex] = i - preIndex;
                s.pop();
            }
            s.push(i);
        }
        return out;
    }
};
// @lc code=end

