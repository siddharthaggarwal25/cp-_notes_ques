#include <bits/stdc++.h>
using namespace std;

int solveLDS(int ind, int lastIndex, int n, vector<int> &v, vector<vector<int>> &dp) {
    if (ind == n)
        return 0;
    if (dp[ind][lastIndex + 1] != -1)
        return dp[ind][lastIndex + 1];
    int take = 0;
    if (lastIndex == -1 || v[lastIndex] > v[ind])
        take = 1 + solveLDS(ind + 1, ind, n, v, dp);
    int nottake = solveLDS(ind + 1, lastIndex, n, v, dp);
    return dp[ind][lastIndex + 1] = max(take, nottake);
}

int solveLIS(int ind, int lastIndex, int n, vector<int> &v, vector<vector<int>> &dp) {
    if (ind == n)
        return 0;
    if (dp[ind][lastIndex + 1] != -1)
        return dp[ind][lastIndex + 1];
    int take = 0;
    if (lastIndex == -1 || v[lastIndex] < v[ind])
        take = 1 + solveLIS(ind + 1, ind, n, v, dp);
    int nottake = solveLIS(ind + 1, lastIndex, n, v, dp);
    return dp[ind][lastIndex + 1] = max(take, nottake);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<vector<int>> dp1(n, vector<int>(n + 1, -1));
    vector<vector<int>> dp2(n, vector<int>(n + 1, -1));

    int lis = solveLIS(0, -1, n, v, dp1);
    int lds = solveLDS(0, -1, n, v, dp2);

    cout << max(lis, lds) << endl;

    return 0;
}
