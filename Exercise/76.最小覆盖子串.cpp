/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128,0);
        int count = 0;  
        for(char c : t) {
            need[c]++;
        }

        count = t.length();
        int l = 0, r = 0, start = 0, size = INT_MAX;
        while(r < s.length())
        {
            char c = s[r];
            if(need[c] > 0)
                count--;
            need[c]--;  //先把右边的字符加入窗口，减到负数，说明有多余的元素

            if(count == 0) {    //档从l到一直增长的r的窗口中，已经包含所需的全部字符时
                while(l < r && need[s[l]] < 0) { //从左l开始缩减窗口，并把相应need++。
                    // 当碰到需要的数量为0，不再是负数，说明不再有多余的。或者碰到>0的数字，就代表不能再减了。
                    need[s[l++]]++;
                }   //此时窗口符合要求。

                if(r - l + 1 < size) {    //更新答案
                    size = r - l + 1;
                    start = l;
                }

                // need[s[l]]++;   //左边界右移之前需要释放need[s[l]]
                // l++;
                // count++;
            }
            r++;    // 继续开始向右寻找右窗口。（因l到r已经有全部tar了，再往右找也是有全部tar，所以count第一次之后就不用管了）
        }
        return size == INT_MAX ? "" : s.substr(start, size);
    }
};
// @lc code=end

