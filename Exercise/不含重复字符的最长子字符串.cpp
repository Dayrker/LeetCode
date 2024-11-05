#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    string input = "ab";
    unordered_map<char, int> char2ix;
    char2ix[input[0]] = 0;
    int l = 0, r = 1;
    int max_ = 0;
    while (r < input.length()) {
        if (char2ix.find(input[r]) != char2ix.end()) {
            if (char2ix[input[r]] >= l) {   // 上一个重复在左指针之前则不做考虑，因为不影响此时的子串
                l = char2ix[input[r]] + 1;
            }
        }
        max_ = max(max_, r - l);
        char2ix[input[r]] = r;
        r++;
    }
    max_ = max(max_, r - l);
    cout << max_ << endl;

    return 0;
}