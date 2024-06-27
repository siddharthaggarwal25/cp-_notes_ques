#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int count(int n, int sum, vector<int> coins , vector< int > &dp)
{
    if (sum == 0)
        return 1;
        if( dp[sum ] != -1 ) return dp[sum];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum - coins[i] >= 0)
            ans = (ans + count(n, sum - coins[i], coins , dp)) % mod;
    }
    return  dp[sum]=ans%mod ;
}
int main()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);
    vector< int > dp( sum+1  , -1);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    cout << count(n, sum, coins , dp ) << endl;

    return 0;
}