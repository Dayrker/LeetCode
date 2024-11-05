# include<iostream>
# include<vector>
using namespace std;

unsigned long long ways = 0;
const unsigned long long mo = 1e9+7;

int FindWays(int pointer, int now_step, int steps, int arrLen, vector<unsigned long long> jiechengs) {
    if (pointer < 0 || pointer > steps - now_step || pointer >= arrLen) {
        // cout << pointer << " " << now_step << " "  << ways << endl;
        return 0;
    }
    if (pointer <= steps - now_step) {
        ways = (ways + jiechengs[steps - now_step] / (jiechengs[pointer] * jiechengs[steps - now_step - pointer])) % mo;
        // cout << pointer << " " << now_step << " "  << ways << endl;
    }

    FindWays(pointer+1, now_step+1, steps, arrLen, jiechengs);
    if (pointer == 1 && now_step == steps - 1) {
        ways = ways;
    } else {
        FindWays(0, now_step+2, steps, arrLen, jiechengs);
    }
    return 0;
}

int numWays(int steps, int arrLen) {
    vector<unsigned long long> jiechengs(steps+1);
    jiechengs[0] = 1;
    jiechengs[1] = 1;
    for (int i = 2; i <= steps; i++) {
        jiechengs[i] = jiechengs[i-1] * i;
    }

    FindWays(0, 0, steps, arrLen, jiechengs);
    // cout << ways << endl;
    return ways;
}


int main() {
    int steps = 3;
    int arrLen = 2;
    cout << numWays(steps, arrLen) << endl;;
}