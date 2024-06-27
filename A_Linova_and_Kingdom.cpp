#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector<int> depth;
vector<int> sz;
vector<vector<int>> adj;
void dfs( int node , int par){

    for( auto child  : adj[node]){
        if( child  == par)continue;
        depth[child] = depth[node] +1;
        dfs( child , node);
        sz[node] += sz[child];
    }
}
int32_t main()
{
    int n, k;
    cin >> n >> k;
    adj.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    depth.assign(n + 1, 0);
    sz.assign(n + 1, 1);
    dfs( 1  , -1 );

    vector<int > vec( n+1 , 0 );
    for( int i=1  ;i<= n  ;i++){
        vec[i] = depth[i] - sz[i] +1;
    }
     sort( vec.begin() +1, vec.end());
     int ans = 0 ;
     while( k--){
        ans  += vec.back();
        vec.pop_back();
     }
     cout<<ans<<endl;


    return 0;
}