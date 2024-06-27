#include <bits/stdc++.h>
using namespace std;
int maxl(int n, int i, vector<int> &v, vector<int> &dp)
{
    if (i == n+1) return 1;
    if (dp[i] != -1) return dp[i];
    int maxi = 1;
    for (int j = i; j <= n; j += i)  if (v[j] > v[i])  maxi = max(maxi, 1 + maxl(n, j, v, dp ));
    return dp[i] = maxi;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n + 1);
        vector<int > dp( n+1, -1 );
        for (int i = 1; i <= n; i++)cin >> v[i];
        int ans = 1;
        for (int i = 1; i <= n; i++) ans = max(ans, maxl(n, i, v, dp));
        cout<<ans<<endl;
    }
    return 0;
}