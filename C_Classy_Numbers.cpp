#include <bits/stdc++.h>
using namespace std;
#define int long long 
int dp[20][2][4];
int solve(string s, int ind, int tight, int count)
{
    if (ind == s.size()) return 1;
    if (dp[ind][tight][count] != -1) return dp[ind][tight][count];
    int limit;
    if (tight)
        limit = s[ind] - '0';
    else
        limit = 9;
    int ans = 0;
    for (int i = 0; i <= limit; i++)
    {
        int updateCount = count;
        if (i != 0)
            updateCount++;
        if (updateCount <= 3)
        {
            int newtight = 0;
            if (tight && (i == (s[ind] - '0')))newtight = 1;
            ans   += solve(s, ind + 1, newtight, updateCount);
        }
    }
    return dp[ind][tight][count] = ans;
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        string s1 = to_string(l-1);
        string s2 = to_string(r);
        memset(dp, -1, sizeof(dp));
        int a = solve(s2, 0, 1, 0);
        memset(dp, -1, sizeof(dp));
        int b = solve(s1, 0, 1, 0);
        cout << a - b << endl;
    }
    return 0;
}