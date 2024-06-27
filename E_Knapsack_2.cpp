#include <bits/stdc++.h>
using namespace std;
#define int  long long
char _;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int32_t main() {
    fast_io;
    int N, W;
    cin >> N >> W;
    vector<int> values(N);
    vector<int> weights(N);
    int total_value = 0;
    for (int i = 0; i < N; ++i) {
        cin >> weights[i] >> values[i];
        total_value += values[i];
    }

    vector<vector<int> > DP(N , vector<int> (total_value + 1, 1e12 + 10));
  dp[0][0]=0;
    for (int i = 1; i < N; i++) {
        for (int j = total_value; j >= 0; j--) {
            DP[i][j] = min(DP[i][j], DP[j - values[i]] + weights[i]);


__builtin_pop
        }
    }

    int answer = 0;
    for (int  i = 0; i <= total_value; i++) {
        if (DP[N-1][i] <= W) {
            answer = i;
        }
    }
    cout << answer << endl;

}