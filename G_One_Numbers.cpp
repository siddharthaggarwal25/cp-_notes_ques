#include <bits/stdc++.h>
using namespace std;
int dp[10][2][80];
bool isPrime(int n)
{
   if (n <= 1) return false;
    if (n == 2) return true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int solve(string s, int ind, int tight, int sum)
{
    if (s.size() == ind)
    {
        if (isPrime(sum))
            return 1;
        return 0;
    }
    if (dp[ind][tight][sum] != -1)return dp[ind][tight][sum];
    int limit;
    if (tight)limit = s[ind] - '0';
    else limit = 9;
    int ans = 0;
    for (int i = 0; i <= limit; i++)
    {
        int nupdatesum = sum + i;
        int newtight = 0;
        if (tight && (i == (s[ind] - '0')))
            newtight = 1;
        ans += solve(s, ind + 1, newtight, nupdatesum);
    }
    return dp[ind][tight][sum] = ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1 = to_string(n - 1);
        memset(dp, -1, sizeof(dp));
        int a = solve(s1, 0, 1, 0);
        string s2 = to_string(m);
        memset(dp, -1, sizeof(dp));
        int b = solve(s2, 0, 1, 0);
        cout << b - a << endl;
    }
    return 0;
}