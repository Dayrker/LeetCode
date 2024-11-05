/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) { return head; }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 切分链表
        fast = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(fast));
    }

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* preHead = new ListNode(0);
        ListNode* node = preHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                node = node->next = l1;
                l1 = l1->next;
            } else {
                node = node->next = l2;
                l2 = l2->next;
            }
        }
        node->next = l1 == nullptr ? l2 : l1;
        return preHead->next;
    }
};
// @lc code=end

