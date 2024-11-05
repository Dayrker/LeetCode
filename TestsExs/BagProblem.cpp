#include <vector>
#include <iostream>
using namespace std;

int max_meiqiang = 10;

class Solution
{
    public:
        int maxTrails(int m, int n) {
            n++;
            vector<vector<int>> dp(m, vector<int>(n, 0));
            for (int j = 0; j <= max_meiqiang; j++) {
                dp[0][j] = 1;
            }

            for (int i = 1; i < m; i++) {
                for (int j = 0; j <= max_meiqiang; j++) {   // 前0-max_qiang环，从0开始累加
                    for (int k = 0; k <= j; k++) {
                        dp[i][j] += dp[i - 1][j - k];
                    }
                }
            }

            for (int i = 1; i < m; i++) {
                for (int j = max_meiqiang + 1; j <= n; j++) {
                    for (int k = 0; k <= max_meiqiang; k++) {   // max_qiang-n环，累加前十个
                        dp[i][j] += dp[i - 1][j - k];
                    }
                }
            }
            return dp[m - 1][n - 1];
        }
};

int main()
{
    // 每枪最多十环，共十枪，90环的排列数。
    int m = 10;
    int n = 90;

    Solution o = Solution();
    cout << o.maxTrails(m, n) << endl;
    return 0;
}