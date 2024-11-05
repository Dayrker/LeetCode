/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */
#include <unordered_set>
using namespace std;

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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while (true) {
            if (fast->next == nullptr || fast->next->next == nullptr) {
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

