/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    void getTopk(vector<int>& keys, vector<int>& values, int start, int end, int k) {
        if (start >= end || start > k - 1 || end <= k - 1) { return; }

        int mid = values[start];
        int left = start, right = end;
        while (left != right) {
            while (left < right && values[right] <= mid) {
                right--;
            }
            swap(keys[left], keys[right]);
            swap(values[left], values[right]);
            while (left < right && values[left] >= mid) {
                left++;
            }
            swap(keys[left], keys[right]);
            swap(values[left], values[right]);
        }
        getTopk(keys, values, start, left - 1, k);
        getTopk(keys, values, left + 1, end, k);
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num2fre;
        for (int num : nums) {
            num2fre[num] += 1;
        }

        int len = num2fre.size();
        vector<int> numbers, fres;
        for (auto iter = num2fre.begin(); iter != num2fre.end(); iter++) {
            numbers.emplace_back(iter->first);
            fres.emplace_back(iter->second);
        }
        getTopk(numbers, fres, 0, len - 1, k);

        vector<int> out;
        for (int i = 0; i < k; i++) {   out.emplace_back(numbers[i]);   }
        return out;
    }
};
// @lc code=end

