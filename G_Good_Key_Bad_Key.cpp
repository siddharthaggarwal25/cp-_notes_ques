#include <bits/stdc++.h>
using namespace std;
#define int long long 
int solve(int ind, int factor, int n, int k, vector<int> &coins , vector< vector<int >>& dp )
{
    if (ind == n) return 0;
    if(factor > 30 )factor = 30 ; 
    if( dp[ind][factor] != -1 )return dp[ind][factor];

    int good = (coins[ind]) / (1 << factor)   - k + solve(ind + 1, factor, n, k, coins , dp);
    int bad = (coins[ind]) / (1 << (factor + 1))    + solve(ind + 1, factor + 1, n, k, coins , dp);

    return dp[ind][factor] =  max(good, bad);
}
int32_t  main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector< vector<int >>dp( n  ,vector<int > ( 31 ,  -1));
        vector<int> coins(n);
        for (int i = 0; i < n; i++)
            cin >> coins[i];
        int ans = solve(0,  0, n, k, coins , dp );
        cout << ans << endl;
    }
    return 0;
}