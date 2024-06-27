#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
vector<int> vis;
vector<int> dp;
vector<vector<pair<int, int>>> adj;
void dfs(int node)
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (vis[child.first])
            continue;
        dp[child.first] = dp[node] ^ (child.second);
        dfs(child.first);
    }
}
int32_t main()
{
    int n;
    cin >> n;
    vis.assign(n + 1, 0);
    dp.resize(n + 1);
    adj.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dp[1] = 0;
    dfs(1);
    // for( int i=1  ;i<= n  ;i++ ){
    //     cout<<1<<" "<<i <<" "<<dp[i]<<endl;
    // }
    // int sum =0 ;
    // for( int i=1  ;i<=n ;i++){
    //     for( int j= i+1  ; j<= n ;j++){
    //         sum += ( dp[i]^dp[j])%mod;
    //         sum =  sum%mod ;
    //     }
    // }
    // cout<<sum<<endl;
    

    int ans=0;
    for(int i=0;i<=60;i++){
        int ct1=0;
        for(int u=1;u<=n;u++){
            if(dp[u]&(1LL<<i)) ct1++;
        }
        int ct0=n-ct1;
        int temp=(((ct0*ct1)%mod)*((1LL<<i)%mod))%mod;
        ans=(ans+temp)%mod;
    }
    cout<<ans<<endl;

    return 0;
}