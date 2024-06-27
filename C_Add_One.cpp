#include <bits/stdc++.h>
using namespace std;
#define int long long 
int mod = 1e9 +7;
int dp[ 200020];
int32_t  main()
{
   
    for (int i = 0; i <= 9; i++)
    {
        dp[i] = 1;
    }
    for (int i = 10; i < 200020; i++)
    {
        dp[i] = (dp[i - 10] + dp[i - 9]) % mod;
    }
    int  t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        while (n > 0)
        {
            int  val = n % 10;
            ans = (ans + dp[val + m]) % mod;
            n /= 10;
        }
        cout << ans << endl;
    }
}