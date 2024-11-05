#include <vector>
#include <iostream>
using namespace std;

class heapSort {
    public:
        vector<int> theNums;
        void sort(vector<int>& nums, int len) {
            // 创建堆，从最后一个非叶子结点开始
            // 最后一个叶子节点的索引值是n-1,它的父节点索引值是[(n-1)-1]/2 = n/2 -1
            for(int i = len / 2 - 1; i >= 0; i--) {
                max_heapify(nums, i, len - 1);
            }

            //堆排序
            for(int i = len - 1; i > 0; i--) {
                swap(nums[0], nums[i]);
                max_heapify(nums, 0, i - 1);
            }

            theNums = nums;
        }
 
        void max_heapify(vector<int>& nums, int start, int end) {   // 实际类似于下沉操作
            int father = start;
            int max_son = start * 2 + 1;

            while (max_son <= end) {
                // 两个子节点中选取最大的那个。然后向后
                if (max_son + 1 <= end && nums[max_son] < nums[max_son + 1]) {
                    max_son++;
                }

                // 若子节点大于父节点，则置换
                if (nums[max_son] > nums[father]) {
                    swap(nums[max_son], nums[father]);
                    father = max_son;
                    max_son = 2 * father + 1;
                } else {
                    return;
                }
            }
        }

        void swap(int& i, int& j) {
            int temp = i;
            i = j;
            j = temp;
        }
};

int main()
{
    vector<int> input = {-2, 3, 5, 7, 0, 1, 9, 87, 21, -10};
    heapSort qs;
    qs.sort(input, input.size());
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " ";
    }
    cout << endl;
    
    return 0;
}
