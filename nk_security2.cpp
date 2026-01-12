#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int getTransformedLength(string word, int t) {
    vector<vector<int>> dp(26, vector<int>(t + 1, 0));

    for (int i = 0; i < 26; ++i) {
        dp[i][0] = 1;
    }

    for (int step = 1; step <= t; ++step) {
        for (int c = 0; c < 25; ++c) {
            dp[c][step] = dp[c + 1][step - 1];
        }
        long long val = dp[0][step - 1] + dp[1][step - 1];
        if (val >= MOD) val -= MOD;
        dp[25][step] = (int)val;
    }

    long long ans = 0;
    for (char ch : word) {
        int idx = ch - 'a';
        ans += dp[idx][t];
        if (ans >= MOD) ans -= MOD;
    }

    return (int)ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string word;
    int t;
    if (!(cin >> word)) return 0;
    cin >> t;
    cout << getTransformedLength(word, t) << '\n';
    return 0;
}
