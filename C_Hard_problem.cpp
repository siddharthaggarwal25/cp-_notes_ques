#include <bits/stdc++.h>
using namespace std;
#define int long long
int solve(int ind, int isrev, vector<int> &cost, vector<string> &arr, vector<vector<int>> &dp)
{
    if (ind == cost.size())
        return 0;
    if (dp[ind][isrev] != -1)
        return dp[ind][isrev];
    int rev = 1e16;
    int not_rev = 1e16;
    string a = arr[ind - 1];
    string b = arr[ind - 1];
    string c = arr[ind];
    string d = arr[ind];
    reverse(b.begin(), b.end());
    reverse(d.begin(), d.end());
    if (isrev == 0) // i-1 index is not revrsed ;
    {
        if (c >= a)
            not_rev = 0 + solve(ind + 1, 0, cost, arr, dp);
        if (d >= a)
            rev = cost[ind] + solve(ind + 1, 1, cost, arr, dp);
    }
    else
    {
        if (c >= b)
            not_rev = solve(ind + 1, 0, cost, arr, dp);
        if (d >= b)
            rev = cost[ind] + solve(ind + 1, 1, cost, arr, dp);
    }

    return dp[ind][isrev] = min(not_rev, rev);
}

int32_t main()
{

    int n;
    cin >> n;
    vector<int> cost(n);
    vector<string> arr(n);
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int val1 = solve(1, 0, cost, arr, dp);
    int val2 = solve(1, 1, cost, arr, dp) + cost[0];

    int val3 = min(val1, val2);
    if (val3 >= 1e16)
        cout << -1 << endl;
    else
        cout << val3 << endl;
    return 0;
}