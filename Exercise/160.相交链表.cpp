/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* nodeA = headA;
        ListNode* nodeB = headB;
        int find = 0;
        while (nodeA || nodeB)
        {
            if (nodeA == nullptr && nodeB == nullptr) {
                break;
            }
            if (nodeA == nodeB) {
                find = 1;
                break;
            }
            nodeA = nodeA == nullptr ? headB : nodeA->next;
            nodeB = nodeB == nullptr ? headA : nodeB->next;
        }
        
        return find == 0 ? nullptr : nodeA;
    }
};
// @lc code=end

