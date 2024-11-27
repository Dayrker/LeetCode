/*
 * @lc app=leetcode.cn id=3223 lang=cpp
 *
 * [3223] 操作后字符串的最短长度
 */
#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    int minimumLength(string s) {
        int countChars[26]{};
        for (char c: s) {
            countChars[c - 'a']++;
        }

        int minL = 0;
        for (int cC: countChars) {
            minL += (cC - 1) % 2 + 1;
        }
        return minL;
    }

    int minimumLength_try1(string s) {
        vector<char> sq;
        unordered_set<int> delete_indexes;
        // unordered_map<char, int> indexChars;
        for (int i = 0; i < s.length(); i++) {
            sq.push_back(s[i]);
            // indexChars.insert({s[i], i});
        }

        // int index = 0;
        int count = 0;
        char nowChar;
        int leftIndex = 0;
        int rightIndex = sq.size() - 1;
        // unordered_map<char, int> leftChars, rightChars;
        while (leftIndex < rightIndex) {
            if (delete_indexes.find(leftIndex) != delete_indexes.end()) {
                leftIndex++;
                continue;
            }
            count = 0;
            for (int i = rightIndex; i > leftIndex && count < 2; i--) { // (rightIndex > leftIndex && count < 2) {
                if (delete_indexes.find(i) != delete_indexes.end()) continue;
                if (sq[i] == sq[leftIndex]) {
                    count += 1;
                    if (count == 1) rightIndex = i;
                }
                // if (count == 1) cout << "Get:" << sq[i] << endl;
                // cout << "leftIndex:" << leftIndex << ", rightIndex:" << rightIndex \
                // << ", i:" << i << ", sq[i]:" << sq[i] << endl;
            }
            // 找到一个左右都有char的char
            if (count == 2) {
                delete_indexes.insert(rightIndex);
                delete_indexes.insert(leftIndex);
            }

            // 到下一个
            rightIndex = sq.size() - 1;
            leftIndex++;
            // cout << "leftIndex:" << leftIndex << endl;
        }
        // cout << "return: " << sq.size() - delete_indexes.size() << endl;
        return sq.size() - delete_indexes.size();
    }
};
// @lc code=end


int main() {
    string c = "mmtmqimnxl";
    Solution So;

    So.minimumLength(c);
}
