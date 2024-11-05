#include <vector>
#include <iostream>
using namespace std;

class quickSort {
    public:
        void sort(vector<int>& nums, int start, int end) {
            if (start >= end) {
                return;
            }

            int mid = nums[start];
            int left = start;
            int right = end;
            while (left != right) { // mid值一直随着交换变位置，直到他该在的位置
                // 找到右边小于mid的值，并交换
                while (left < right && nums[right] >= mid) {
                    right--;
                }
                swap(nums[left], nums[right]);

                // 找到左边大于mid的值，并交换
                while (left < right && nums[left] <= mid) {
                    left++;
                }
                swap(nums[left], nums[right]);
            }
            sort(nums, start, left - 1);
            sort(nums, left + 1, end);
        }

        void swap(int& a, int& b) {
            int temp = a;
            a = b;
            b = temp;
        }
};

int main()
{
    vector<int> input = {-2, 3, 5, 7, 0, 1, 9, 87, 21, -10};
    quickSort qs;
    qs.sort(input, 0, input.size() - 1);
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " ";
    }
    return 0;
}
