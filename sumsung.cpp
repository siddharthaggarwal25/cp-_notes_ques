#include <bits/stdc++.h>
using namespace std;

vector<int> oil, prefixSum;
vector<vector<int>> dp;
int m, n;

int getSum(int start, int end) {
    if (start <= end) {
        return prefixSum[end + 1] - prefixSum[start];
    } else {
        return prefixSum[m] - prefixSum[start] + prefixSum[end + 1];
    }
}

int solve(int idx, int companiesLeft) {
    if (companiesLeft == 1) {
        return getSum(idx, (idx + m - 1) % m);
    }
    
    if (dp[idx][companiesLeft] != -1) {
        return dp[idx][companiesLeft];
    }
    
    int minDifference = INT_MAX;
    
    for (int i = 1; i < m; ++i) {
        int endIdx = (idx + i - 1) % m;
        int currentSum = getSum(idx, endIdx);
        int remainingSum = solve((idx + i) % m, companiesLeft - 1);
        
        int currentDifference = max(currentSum, remainingSum) - min(currentSum, remainingSum);
        minDifference = min(minDifference, currentDifference);
    }
    
    return dp[idx][companiesLeft] = minDifference;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n >> m;
        oil.resize(m);
        prefixSum.resize(m + 1, 0);
        dp.assign(m, vector<int>(n + 1, -1));
        
        for (int i = 0; i < m; ++i) {
            cin >> oil[i];
            prefixSum[i + 1] = prefixSum[i] + oil[i];
        }
        
        int ans = INT_MAX;
        
        for (int i = 0; i < m; ++i) {
            ans = min(ans, solve(i, n));
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
