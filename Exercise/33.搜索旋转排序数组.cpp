/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
    vector<int> Nums;

public:
    int search(vector<int>& nums, int target) {
        Nums = nums;
        int nums_len = nums.size();

        return GetIndex(target, 0, nums_len-1);
    }

    int GetIndex(int target, int l, int r) {
        if (l > r) {
            return -1;
        }

        int mid = (l + r) / 2;
        if (target > Nums[mid]) {
            return target > Nums[r] && Nums[mid] < Nums[l] ? GetIndex(target, l, mid-1) : GetIndex(target, mid+1, r);
        } else if (target < Nums[mid]) {
            return target < Nums[l] && Nums[mid] >= Nums[l] ? GetIndex(target, mid+1, r) : GetIndex(target, l, mid-1);
        } else {
            return mid;
        }

        /**
        if (Nums[l] < Nums[r]) {
            if (target > Nums[mid]) {
                return GetIndex(target, mid+1, r);
            } else if (target < Nums[mid]) {
                return GetIndex(target, l, mid-1);
            } else {
                return mid;
            }
        } else {
            if (Nums[mid] >= Nums[l]) {
                if (target > Nums[mid]) {
                    return GetIndex(target, mid+1, r);
                } else if (target < Nums[mid]) {
                    return target >= Nums[l] ? GetIndex(target, l, mid-1) : GetIndex(target, mid+1, r);
                } else {
                    return mid;
                }
            } else {
                if (target > Nums[mid]) {
                    return target > Nums[r] ? GetIndex(target, l, mid-1) : GetIndex(target, mid+1, r);
                } else if (target < Nums[mid]) {
                    return GetIndex(target, l, mid-1);
                } else {
                    return mid;
                }
            }
        }*/
    }
};
// @lc code=end

