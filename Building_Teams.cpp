#include<bits/stdc++.h>
using namespace std;
bool dfs ( int node , vector< vector<int >> & adj , vector< int > & vis  , vector< int> & color){
    vis[node] =1 ;
    for( auto child : adj[node]){
         if( vis[child]){
            if ( color[child] == color[node] )return false;
         }else{
            if( color[node] ==1 ){
                color[child] =2 ;
            }else{
                color[child ] =1 ;
            }
            bool flag = dfs( child , adj , vis , color);
            if( !flag)return false;
         }
    }
    return true ;
}
int  main (){
     int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector< int >  vis( n+1  , 0 );
    vector< int > color( n+1  , 0 );
    bool check = true ;
    for( int i=0 ;i< n ;i++){
        if( ! vis[i]){
            color[i] =  1;
           check  =  check & dfs(  i , adj , vis , color );
        }
    }
    if( check){
        for( int i=1  ;i<= n  ;i++){
            cout<<color[i]<<" ";
        }
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
return 0;
}