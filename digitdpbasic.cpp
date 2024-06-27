#include <bits/stdc++.h>
using namespace std;
int dp[20][2][20];
int solve(string s, int ind, int tight, int count)
{
    if (ind == s.size())
        return count;
    if (dp[ind][tight][count] != -1)
        return dp[ind][tight][count];

    int limit;
    if (tight)
        limit = s[ind];
    else
        limit = 9;
    int ans = 0;
    for (int i = 0; i <= limit; i++)
    {
        int updateCount = count;
        if (i == 3) updateCount++;
        int newtight = 0;
        if (tight && i == s[ind])  newtight = 1;
        ans += solve(s, ind + 1, newtight, updateCount);
    }
    return dp[ind][tight][count] = ans;
}
int main()
{
    int l, r;
    cin >> l >> r;
    memset(dp, -1, sizeof(dp));
    string s1 = to_string(l);
    string s2 = to_string(r);
    int a = solve(s1, 0, 1, 0); // string .. ind ..tight ..count
    memset(dp, -1, sizeof(dp));
    int b = solve(s2, 0, 1, 0); // string .. ind ..tight ..count
    cout << b << a << endl;

    return 0;
}