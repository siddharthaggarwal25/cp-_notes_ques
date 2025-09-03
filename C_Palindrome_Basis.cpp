#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

vector<int> v;

bool isp(int num)
{
    string s = to_string(num);
    int a = 0, b = s.size() - 1;
    while (a <= b)
    {
        if (s[a] != s[b])
            return false;
        a++, b--;
    }
    return true;
}

int solve(int amount, int ind, int target, vector<vector<int>> &dp)
{
    if (amount == target)
        return 1;
    if (amount > target)
        return 0;
    if (ind >= v.size())
        return 0;

    if (dp[amount][ind] != -1)
        return dp[amount][ind];

    int take = solve(amount + v[ind], ind, target, dp);
    int nottake = solve(amount, ind + 1, target, dp);

    return dp[amount][ind] = (take + nottake) % mod;
}

int32_t main()
{
    for (int i = 1; i <= 40000; i++)
        if (isp(i))
            v.push_back(i);

    vector<vector<int>> dp(40000 + 1, vector<int>(v.size(), -1));
    cout << solve(0, 0, 40000, dp) << "\n";
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
       cout<<dp[n][v.size()-1]<<endl;
    }
    return 0;
}
