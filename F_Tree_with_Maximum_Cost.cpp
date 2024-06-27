#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> adj;
vector<int> weight;
vector<int> ans;
vector<int> dp;
vector<int> sz;

void dfs(int node, int parent)
{
    dp[node] = 0;
    sz[node] = weight[node];
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        dfs(child, node);
        dp[node] += dp[child] + sz[child];
        sz[node] += sz[child];
    }
}
void rerooting(int node, int parent)
{
    ans[node] = dp[node];
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        dp[node] = dp[node] - dp[child] - sz[child];
        sz[node] = sz[node] - sz[child];
        dp[child] = dp[child] + sz[node] + dp[node];
        sz[child] = sz[child] + sz[node];
        rerooting(child, node);
       
    }
}

int32_t main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    sz.resize(n + 1);
    ans.resize(n + 1);
    weight.resize(n + 1);
    dp.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    rerooting(1, 0);
    int an  =0 ;
    for( int i=1  ;i<=  n  ; i++){
        
         an = max(an , ans[i] );
    }
    cout<<an<<endl;

    return 0;
}