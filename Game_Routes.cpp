#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
// int dfs(int node, int n, vector<int> &dp, vector<vector<int>> &adj)
// {

//     if (node == n)
//         return 1;

//     if (dp[node] != -1)
//         return dp[node];
//     int cnt = 0;
//     for (auto child : adj[node])
//     {
//         cnt += dfs(child, n, dp, adj);
//         cnt  = cnt%mod ;
//     }

//     return dp[node] = cnt%mod;
// }

void dfs2(int node, stack<int> &st, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[node] = 1;
    for (auto child : adj[node])
    {   
        if( vis[child] ==1 )continue;
        dfs2(child, st, vis, adj);
    }
    st.push(node);
}
int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> dp(n + 1, 0);
    vector<int> vis(n + 1, 0);
    stack<int> st;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs2(1, st, vis, adj);
    dp[1] = 1 ;

    while( !st.empty()){
         int node = st.top();
         st.pop();

         for( auto child  : adj[node]){
             dp[child ] += dp[node];
             dp[child] = dp[child]%mod;
         }
    }
    cout<<dp[n]%mod<<endl;





    return 0;
}