#include <bits/stdc++.h>
using namespace std;
#define int long long

void dfs( int node , vector<vector<pair<int , int >>>& e , vector<int > &dp , vector<int > &id){
     
      for( auto it  : e[node]){
         if( dp[it.first] ==0){
             dp[it.first] = dp[node] + ( it.second< id[node]);
             id[it.first] = it.second;
             dfs( it.first,e,dp,id); 
         }
      }
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<pair<int, int>>> e(n + 1);
        vector<int> dp(n + 1, 0), id(n + 1, 0);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            e[u].push_back({v, i});
            e[v].push_back({u, i});
        }

        dp[1] =1  ;
        dfs( 1  , e , dp , id  );

        int ans  = *max_element( dp.begin() +1 , dp.end());
        cout<<ans<<endl;
    }
    return 0;
}