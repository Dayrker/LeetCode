/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * out = new ListNode;
        ListNode * out_t = out;
        int l1_val = 0;
        int l2_val = 0;
        int jinwei = 0;

        while (l1 || l2)
        {
            out_t->next = new ListNode;
            out_t = out_t->next;

            l1_val = l1 == nullptr ? 0 : l1->val;
            l2_val = l2 == nullptr ? 0 : l2->val;

            out_t->val = (l1_val + l2_val + jinwei) % 10;
            jinwei = (l1_val + l2_val + jinwei) / 10;

            l1 = l1? l1->next: l1;
            l2 = l2? l2->next: l2;
        }

        out_t->next = jinwei > 0 ? new ListNode(jinwei) : nullptr;
        return out->next;
    }
};
// @lc code=end

