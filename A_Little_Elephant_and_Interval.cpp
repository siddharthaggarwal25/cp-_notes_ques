#include <bits/stdc++.h>
using namespace std;
#define int long long 
int dp[20][2][11];
int solve(string s, int ind, int tight, int last)
{
    if (ind == (s.size() - 1)) return 1 ; 

    if (dp[ind][tight][last] != -1)
        return dp[ind][tight][last];
    int limit;
    if (tight)
        limit = s[ind] - '0';
    else
        limit = 9;
    int ans = 0;
    for (int i = 0; i <= limit; i++)
    {
        int newtight = 0;
        if (tight && i == (s[ind] - '0')) newtight = 1;
        ans += solve(s, ind + 1, newtight, i );
    }
    return dp[ind][tight][last] = ans;
}
int32_t main()
{
    int l, r;
    cin >> l >> r;
    string s1 = to_string(l - 1);
    string s2 = to_string(r);
    memset(dp, -1, sizeof(dp));
    int right = solve(s2, 0, 1, 0);
    memset(dp, -1, sizeof(dp));
    int left = solve(s1, 0, 1, 0);
    cout << right <<" "<<left  << endl;
    return 0;
}