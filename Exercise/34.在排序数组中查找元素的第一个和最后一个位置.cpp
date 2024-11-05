/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
    vector<int> Nums;

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int nums_len = nums.size();
        vector<int> out{-1, -1};
        if (nums.size() == 0) {
            return out;
        }
        Nums = nums;

        out[0] = get_sOe(0, nums_len-1, target, 0);
        out[1] = get_sOe(0, nums_len-1, target, 1);
        return out;
    }

    int get_sOe(int l, int r, int target, int sOe)
    {
        if (r < l) {
            return -1;
        } else if (r == l) {
            return Nums[l] == target ? l : -1;
        }

        int mid = (l + r) / 2;
        if (Nums[mid] < target) {
            return get_sOe(mid + 1, r, target, sOe);
        } else if (Nums[mid] > target) {
            return get_sOe(l, mid - 1, target, sOe);
        } else {
            return sOe == 0 ? get_sOe(Nums[l] < target ? l + 1 : l, mid, target, sOe) 
                : get_sOe(Nums[mid+1] == target? mid + 1 : mid, Nums[r] > target ? r - 1 : r, target, sOe);
        }
    }
};
// @lc code=end

