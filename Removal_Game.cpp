#include <bits/stdc++.h>
using namespace std;
#define int long long 
// vector<vector<vector<int>>> dp(5000, vector<vector<int>>(5000, vector<int>(2, -1)));
vector<vector<int>> dp(5000, vector<int>(5000, -1));
int fun(int i, int j, vector<int> &arr)
{
    if (i > j)
        return 0;

    // Lookup case
    if (dp[i][j] != -1)
        return dp[i][j];

    // Recursion case
    int op1 = arr[i] + min(fun(i + 2, j, arr), fun(i + 1, j - 1, arr));
    int op2 = arr[j] + min(fun(i + 1, j - 1, arr), fun(i, j - 2, arr));

    return dp[i][j] = max(op1, op2);
}
int32_t main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << fun(0, n - 1, arr) << endl;
    return 0;
}