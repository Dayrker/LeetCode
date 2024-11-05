/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while (true) {  // 先此循环找到两个指针相遇的地方
            if (fast->next == nullptr || fast->next->next == nullptr) {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                break;
            }
        }

        // 可证明fast所处位置i,环初始位置Ini到i的距离，为head到Ini的距离m
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
// @lc code=end

