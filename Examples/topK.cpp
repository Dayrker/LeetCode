#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> vec(k, 0);
        if (k == 0) { // 排除 0 的情况
            return vec;
        }
        priority_queue<int> Q;
        for (int i = 0; i < k; ++i) {
            Q.push(arr[i]);
        }
        for (int i = k; i < (int)arr.size(); ++i) {
            if (Q.top() > arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            vec[i] = Q.top();
            Q.pop();
        }
        return vec;
    }
};

int main()
{
    vector<int> input = {-2, 3, 5, 7, 0, 1, 9, 87, 21, -10};
    int k = 2;
    nth_element(input.begin(), input.begin() + k - 1, input.end(), greater<int>());
    for (int num : input) {    cout << num << ' ';    }
    cout << endl;

    Solution o;
    vector<int> out = o.smallestK(input, 4);
    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << " ";
    }
    return 0;
}

