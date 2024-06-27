#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector<int> size_;
vector<int> dp;
vector<vector<int>> adj;
vector<int > ans;
void dfs(int node, int parent)
{
    size_[node] = 1;
    dp[node] = 0;
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        dfs(child, node);
        dp[node] += dp[child] + size_[child ];
        size_[node] += size_[child];
    }
}
void rerooting ( int node  , int  parent ){
    ans[node] = dp[node];
    for( auto child : adj[node]){
        if( child  == parent )continue;
        dp[node] = dp[node] -   dp[child ] -size_[child];
        size_[node] -= size_[child ];
        dp[child ] += dp[node] + size_[node];
        size_[child]  += size_[node];
        rerooting( child , node);
        dp[ child ] = dp[child ]  - dp[node] - size_[node];
        size_[child ] -= size_[node  ];
        dp[node ] = dp[node] +   dp[child ] +size_[child];
        size_[node]  += size_[child ];

    }

}
int32_t main()
{
    int n;
    cin >> n;
    adj.resize((n + 1));
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    size_.assign(n + 1, 0);
    dp.assign(n + 1, 0);
    ans.assign( n+1, 0 );
    dfs(1, 1);
    rerooting( 1 , 1);
    for( int i=1  ;i<= n  ;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}