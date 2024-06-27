#include <bits/stdc++.h>
using namespace std;
#define int long long
    vector<vector<int>> dp ;
int f(int ind, int sum, vector<int> &coins, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 0;
    if (ind < 0)
        return 1e8;
    if (dp[ind][sum] != -1)
        return dp[ind][sum];
    int nottake = f(ind - 1, sum, coins, dp);
    int take = 1e8;
    if (sum - coins[ind] >= 0)
        take = 1 + f(ind, sum - coins[ind], coins, dp);
    return dp[ind][sum] = min(nottake, take);
}
int32_t main()
{
    ios_base :: sync_with_stdio;
    cin.tie(NULL);
    int n, target;
    cin >> n >> target;
    dp.assign(  n+1 , vector< int >  ( target+1  , 0  ));
    for( int i=0 ;i<= n  ;i++){
        dp[i][0 ] = 0 ;
    }
    for( int i= 0 ;i<= sum  ; i++){
        dp[0 ] [ i ] = 1e8 ;
    }
    for( int i=1  ;i<= n  ;i++){
        for( int j= 1 ; )
    }
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    int val = f(n - 1, target, coins, dp);
    if( val == 1e8 ) cout<<-1<<endl;
    else cout<< val<<endl;

    return 0;
}