/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return head;
        } else if (head->next == nullptr) {
            return nullptr;
        }

        ListNode * fast = head;
        int i = 1;
        while (i++ != n) {
            fast = fast->next;
        }
        if (fast->next == nullptr) {
            return head->next;
        }

        ListNode * pre = new ListNode(0, head);
        while (fast->next != nullptr) {
            fast = fast->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};
// @lc code=end

