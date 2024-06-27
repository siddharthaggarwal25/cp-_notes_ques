#include<bits/stdc++.h>
using namespace std;
int  dfs( int node  , vector< int > & vis  , vector< int > & ans , vector< vector< int >> & adj  ){

    vis[node] = 1;
    int sz =0 ;
    for( auto child : adj[node]){
        if( !vis[child ]){
             sz += dfs( child , vis  , ans  , adj )+1;
        }
    }
    return ans[node] = sz  ;
    
}
int  main (){
     int n ;
     cin>>n ;
     vector< vector<int >>  adj(  n+1 );
     for( int i = 2 ;i<= n ;i++){
        int x ;
        cin>>x ;
        adj[x].push_back( i );
     }

     vector< int >  ans ( n+1  , 0 );
     vector< int > vis( n+1 , 0 );
     for( int i =1  ;i<= n ;i++){
        if( !vis[i]){
            dfs( i , vis , ans , adj  );
        }
     }
     for( int i=1  ;i<=  n  ;i++){
        cout<<ans[i]<<" ";
     }
return 0;
}