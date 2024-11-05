#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, int left, int mid, int right)
{
    int i = left, j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp.emplace_back(nums[i++]);
        } else {
            temp.emplace_back(nums[j++]);
        }
    }
    // 左右序列剩下的元素填充进temp
    while (i <= mid) {    temp.emplace_back(nums[i++]);    }
    while (j <= right) {    temp.emplace_back(nums[j++]);    }
    
    for (int num : temp) {  nums[left++] = num;   }
}

void sort(vector<int>& nums, int i, int j)
{
    if (i < j) {
        int mid = (i + j) / 2;
        sort(nums, i, mid);
        sort(nums, mid + 1, j);
        merge(nums, i, mid, j);
    }
}

void swap(int& i, int& j)
{
    int temp = j;
    j = i;
    i = temp;
}

int main() {
    vector<int> input = {3, 4, 1, 2};
    sort(input, 0, input.size() - 1);
    for (int num : input) {
        cout << num << ' ';
    }
    return 0;
}