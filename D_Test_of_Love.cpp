#include <bits/stdc++.h>
using namespace std;
#define int long long
map<char, int> mp;
vector<vector<vector<int>>> dp;
string s;
int solve(int ind, char maxi, int done)
{
    if (ind < 0)
        return 0;
    if (dp[ind][maxi - 'A'][done] != INT_MIN)
        return dp[ind][maxi - 'A'][done];
    if (done == 1)
    {
        if (s[ind] >= maxi)
            return dp[ind][maxi - 'A'][done] = mp[s[ind]] + solve(ind - 1, s[ind], 1);
        else
            return dp[ind][maxi - 'A'][done] = -mp[s[ind]] + solve(ind - 1, maxi, 1);
    }
    int ans = INT_MIN;
    if (s[ind] >= maxi)
        ans = max(ans, mp[s[ind]] + solve(ind - 1, s[ind], 0));
    else
        ans = max(ans, -mp[s[ind]] + solve(ind - 1, maxi, 0));

    for (char i = 'A'; i <= 'E'; i++)
    {
        if (i == s[ind])
            continue;
        if (i >= maxi)
            ans = max(ans, mp[i] + solve(ind - 1, i, 1));
        else
            ans = max(ans, -mp[i] + solve(ind - 1, maxi, 1));
    }

    return dp[ind][maxi - 'A'][done] = ans;
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        int n = s.size();
        mp['A'] = 1;
        mp['B'] = 10;
        mp['C'] = 100;
        mp['D'] = 1000;
        mp['E'] = 10000;
        dp.clear();
        dp.assign(n, vector<vector<int>>(6, vector<int>(2, INT_MIN)));
        int ans = solve(n - 1, 'A', 0);
        cout << ans << endl;
    }

    return 0;
}