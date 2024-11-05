/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> out;
        unordered_map<string, vector<string>> Mymap;

        for (string & str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            Mymap[key].emplace_back(str);
        }

        for (auto iter = Mymap.begin(); iter != Mymap.end(); ++iter) {
            out.emplace_back(iter->second);
        }
        return out;
    }
};
// @lc code=end

