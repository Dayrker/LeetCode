/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode * node_pre = new ListNode(head->val, nullptr);
        ListNode * node_last = head->next;
        while (node_last != nullptr)
        {
            head = node_last;
            node_last = head->next;
            head->next = node_pre;
            node_pre = head;
        }
        
        return head;
    }
};
// @lc code=end

