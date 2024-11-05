#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int N;

void getBrackets(vector<string>& out, string br, vector<char> lbs, vector<char> rbs, int num_l)
{
    if (lbs.size() == 0 && num_l == N) {
        if (rbs.size() == 0) {  // 左右都用完
            out.emplace_back(br);
        } else {
            while (rbs.size() > 0) {  // 剩下右括号
                br = br +(rbs[rbs.size() - 1]);
                rbs.pop_back();
            }
            out.emplace_back(br);
        }
        return;
    }

    if (rbs.size() > 0) {
        rbs.pop_back();
        getBrackets(out, br + ')', lbs, rbs, num_l);
        rbs.emplace_back(')');
    }
    rbs.emplace_back(')');
    lbs.pop_back();
    getBrackets(out, br + '(', lbs, rbs, num_l + 1);
}

int main()
{
    vector<string> out;
    int n = 0;
    cin >> n;
    N = n;

    vector<char> leftBs(n - 1, '(');
    vector<char> rightBs(1, ')');
    string br = "(";
    getBrackets(out, br, leftBs, rightBs, 1);
    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << endl;
    }

    return 0;
}
