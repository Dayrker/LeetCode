/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */
#include <unordered_map>
using namespace std;

// @lc code=start
class LRUCache {
    private:
        struct ListNode {
            int key;
            int val;
            ListNode* next;
            ListNode() { key = 0; val = 0; next = nullptr; }
            ListNode(int k, int v, ListNode* n) { key = k; val = v; next = n; }
        };
        int maxCap;
        int numCache;
        ListNode* head;
        ListNode* tail;
        unordered_map<int, ListNode*> caches;   // 存储缓存的map
    public:
        LRUCache(int capacity) {
            maxCap = capacity;
            numCache = 0;
            tail = head = new ListNode();
        }
        
        int get(int key) {
            if (caches.find(key) != caches.end()) {
                // 动过了，给他拉到链表尾端
                // 先把自己从链表上移出
                int temp = caches[key]->val;
                // 然后在尾端把自己复制过去，加上
                if (head != tail) {
                    // 删掉caches[key]指向的ListNode，并且把后边的ListNode对应地址设置好
                    if (caches[key]->next == tail) {
                        *caches[key] = *(caches[key]->next);
                        tail = caches[key];
                    } else {
                        *caches[key] = *(caches[key]->next);
                        caches[caches[key]->key] = caches[key];
                    }
                    // 把之前删掉的ListNode加到链表尾部
                    *tail = ListNode(key, temp, new ListNode(0, 0, nullptr));
                    // tail->key = key;
                    // tail->val = temp;
                    // tail->next = new ListNode(0, 0, nullptr);

                    caches[key] = tail;
                    tail = tail->next;
                }
                return temp;
            }
            return -1;
        }
        
        void put(int key, int value) {
            if (caches.find(key) != caches.end()) { // 关键字key已存在
                caches[key]->val = value;
                this->get(key);
            } else {                                // 关键字key不存在
                if (numCache == maxCap) {           // 缓存容量达到上限 
                    ListNode* Del = head;           // 此时准备删除链表头端数据，即最久没用过的
                    caches.erase(head->key);        // 并将其在caches中删除
                    head = head->next;
                    if (head == tail->next) {
                        head = tail;
                    }

                    delete Del;
                    numCache--;
                }
                // 然后在尾端把自己复制过去，加上
                *tail = ListNode(key, value, new ListNode(0, 0, nullptr));
                // tail->key = key;
                // tail->val = value;
                // tail->next = new ListNode(0, 0, nullptr);
                // 保存位置
                caches[key] = tail;
                tail = tail->next;
                numCache++;
            }
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

