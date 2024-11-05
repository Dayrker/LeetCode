/*
 * @lc app=leetcode.cn id=1823 lang=cpp
 *
 * [1823] 找出游戏的获胜者
 */
#include <queue>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q1, q2;
        for (int i = 1; i <= n; i++) {  q1.push(i); }
        if (k <= 1) {   return n;   }

        int count = 0;
        while (q1.size() + q2.size() > 1) {
            while (!q1.empty()) {
                count += 1;
                if (count == k) {
                    count = 0; 
                } else {  
                    q2.push(q1.front());
                }
                q1.pop();
            }
            if (q1.size() + q2.size() == 1) {   break;  }

            while (!q2.empty()) {
                count += 1;
                if (count == k) {
                    count = 0; 
                } else {  
                    q1.push(q2.front());
                }
                q2.pop();
            }
        }
        
        // while (!q1.empty()) { cout << q1.front(); q1.pop();  }
        return q1.empty() ? q2.front() : q1.front();
    }
};
// @lc code=end

