#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

class TK {
    public:
        int k;  // topK
        int size;
        bool big = true;    // bigger or smaller?
        vector<int> heap;
        TK(int K, bool Big = false) : k(K), big(Big), size(0) {  heap = vector<int>(k, INT_MIN);  }

        // ----methods----
        void add(int num) { // 给爷加
            if (big) {  num = - num;  }

            if (size < k) {
                heap[size++] = num;
                rise(size - 1);
            } else {    // 优先队列满了的时候
                if (heap[0] > num) {
                    heap[0] = num;
                    sink(0);
                }
            }
        }

        void sink(int index) {   // 实际类似于下沉操作
            int father = index;
            int max_son = index * 2 + 1;

            while (max_son <= size - 1) {
                // 两个子节点中选取最大的那个。然后向后
                if (max_son + 1 <= size - 1 && heap[max_son] < heap[max_son + 1]) {
                    max_son++;
                }

                // 若子节点大于父节点，则置换
                if (heap[max_son] > heap[father]) {
                    swap(heap[max_son], heap[father]);
                    father = max_son;
                    max_son = 2 * father + 1;
                } else {
                    return;
                }
            }
        }

        void rise(int index) {   // 上浮操作
            int father = index / 2;
            while (index > 0) {
                if (heap[index] > heap[father]) {
                    swap(heap[index], heap[father]);
                    index = father;
                    father = index / 2;
                } else {
                    return;
                }
            }
        }
};

int main()
{
    vector<int> input = {-2, 3, 5, 7, 0, 1, 9, 87, 21, -10};
    bool big = true;
    TK myTK = TK(5, big);
    for (int num : input) {
        myTK.add(num);
    }

    for (int num : myTK.heap) {
        if (big) {  num = - num;  }
        cout << num << ' ';
    }
    return 0;
}