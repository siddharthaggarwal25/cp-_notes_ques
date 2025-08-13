#include <bits/stdc++.h>
using namespace std;

void dfs( int node, int par , vector<vector<int >>& adj  , vector<int > & dp) {
       
    for ( auto child  : adj[node]){
        if( child == par)continue;
        dfs( child , node, adj , dp );
        if(dp[child ] !=0 )dp[node] += dp[child];
        else dp[node ] += 1 ;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        vector<int > dp ( n+1 , 0);
        int start ;
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for( int i=1  ;i<=n ;i++){
             if( adj[i].size() ==1 ){
                start  = i ;
                break ;
             }
        }

        dfs ( start, -1 , adj , dp);

        cout<<dp[start]<<endl;
    }
    return 0;
}