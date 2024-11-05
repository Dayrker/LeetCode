/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) {
            return head;
        }

        int i = 1;
        ListNode * left_pre = nullptr;
        ListNode * node = head;
        while (i++ != left) {
            left_pre = node;
            node = node->next;
        }
        i = i - 1;
        ListNode * NL = i == 1 ? new ListNode(head->val, nullptr) : node;

        ListNode * node_pre = NL;
        ListNode * node_last = node->next;
        while (i++ != right) {
            node = node_last;
            node_last = node->next;
            node->next = node_pre;
            node_pre = node;
        }
        ListNode * NR = node;
        
        NL->next = node_last;
        if (left_pre == nullptr) {
            return NR;
        } else {
            left_pre->next = NR;
            return head;
        }
    }
};
// @lc code=end

