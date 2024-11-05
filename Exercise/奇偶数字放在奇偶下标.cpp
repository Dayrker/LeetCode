#include <iostream>
#include <vector>
using namespace std;

void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int inLen = input.size();
    int ji = 0, ou = 0;
    while (2 * ou < inLen && 2 * ji + 1 < inLen) {
        if (input[inLen - 1] % 2 == 0) {
            swap(input[2 * ou], input[inLen - 1]);
            ou++;
        } else {
            swap(input[2 * ji + 1], input[inLen - 1]);
            ji++;
        }
    }
    for (int i = 0; i < inLen; i++) {
        cout << input[i] << " ";
    }

    return 0;
}