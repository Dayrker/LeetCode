/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
private:
    int len;
    // vector<char> charArray;
    string s;
    unordered_set<string> validExpressions;
    void dfs(int index, int leftCount, int rightCount, int leftRemove, int rightRemove, string path) {
        if (index == len) {
            if (leftRemove == 0 && rightRemove == 0) {
                validExpressions.insert(path);
            }
            return;
        }

        char character = s[index];
        // 可能操作1：删除当前所遇到的字符
        if (character == '(' && leftRemove > 0) { // 可尝试删除左括号
            dfs(index + 1, leftCount, rightCount, leftRemove - 1, rightRemove, path);
        }
        if (character == ')' && rightRemove > 0) { // 可尝试删除右括号
            dfs(index + 1, leftCount, rightCount, leftRemove, rightRemove - 1, path);
        }
        // 可能操作2：保留当前遍历到的字符
        if (character != '(' && character != ')') {
            // 若不是括号，则直接进行下一步遍历（保存字符）
            dfs(index + 1, leftCount, rightCount, leftRemove, rightRemove, path + character);
        } else if (character == '(') {
            // 考虑左括号
            dfs(index + 1, leftCount + 1, rightCount, leftRemove, rightRemove, path + character);
        } else if (rightCount < leftCount) {
            // 考虑右括号
            dfs(index + 1, leftCount, rightCount + 1, leftRemove, rightRemove, path + character);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        len = s.length();
        this->s = s;

        // 第1步：遍历一次，计算多余的左右括号
        int leftRemove = 0;
        int rightRemove = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                leftRemove++;
            } else if (s[i] == ')') {   // 遇到右括号时，需要根据已经存在的左括号数量决定
                if (leftRemove == 0) {
                    rightRemove++;
                } else {    // 关键：一个右括号出现可以抵消之前遇到的左括号
                    leftRemove--;
                }
            }
        }

        // 第2步：回溯算法，尝试每一种可能的删除操作
        string path;
        dfs(0, 0, 0, leftRemove, rightRemove, path);
        vector<string> out;
        for (string o : validExpressions) {    out.emplace_back(o);    }
        return out;
    }
};
// @lc code=end

