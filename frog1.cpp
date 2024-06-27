
#include <bits/stdc++.h>
using namespace std;
int dp[100001];

int solve(int t, vector<int> &v)
{
    if (t == 0)
    {
        return 0;
    }
    if (dp[t] != -1)
    {
        return dp[t];
    }
    int one = solve(t - 1, v) + abs(v[t - 1] - v[t]);
    int two = (t > 1) ? solve(t - 2, v) + abs(v[t - 2] - v[t]) : INT_MAX;
    return dp[t] = min(one, two);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << solve(n - 1, arr) << endl;
    ;

    return 0;
}