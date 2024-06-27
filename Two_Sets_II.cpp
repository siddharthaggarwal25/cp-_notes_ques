#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int count(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp)
{

    if (ind < 0)
    {
        if (sum == 0)
            return 1;
        return 0;
    }
    if (dp[ind][sum] != -1)
        return dp[ind][sum];
    int nottake = count(ind - 1, sum, arr, dp);
    int take = 0;
    if (sum - arr[ind] >= 0)
        take = count(ind - 1, sum - arr[ind], arr, dp);
    return dp[ind][sum] = (take % mod + nottake % mod) % mod;
}
int32_t main()
{
    int n;
    cin >> n;
    vector<int> arr;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        arr.push_back(i);
        sum += i;
    }
    if (sum % 2 != 0)
    {
        cout << 0 << endl;
    }
    else
    {
        vector<vector<int>> dp(n , vector<int>(sum/2+1, -1));
        cout << count(n - 1, sum / 2, arr, dp) / 2;
    }

    return 0;
}