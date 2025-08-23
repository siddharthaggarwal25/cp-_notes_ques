#include<bits/stdc++.h>
using namespace std;
void dfs( int node, vector<int> & vis , vector<vector<int>>&adj){
    vis[node] =1;
    for( auto child : adj[node]){
      if ( vis[child] )continue;
      dfs( child , vis , adj );
    }
}
int  main (){
    int n , m ;
    cin>>n>>m ;
    vector<vector<int >>adj ( n+1);
    for( int i =0  ;i< m  ;i++){
       int u ,v ;
       cin>>u>>v ;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    vector<int >vis( n+1  , 0);
    vector <int > ans;
    for( int i=1  ;i<=n  ;i++){
       if( vis[i] == 0)dfs( i , vis, adj ) , ans.push_back( i);
    }
    cout<<ans.size()-1<<endl;
    for( int i=0 ;i<ans.size()-1 ;i++){
      cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
return 0;
}