#include<bits/stdc++.h>
using namespace std;
void dfs( int node, int par , vector<vector<int >>&adj, vector<int >&dis , int depth){
    dis[node] = depth;
    for( auto child  : adj[node]){
        if( child == par)continue;
        dfs( child , node , adj, dis, depth+1);
    }
}
int  main (){
     int n ;
     cin>>n ;
     vector<vector<int >> adj( n+1);
     for( int i= 1 ;i< n  ;i++){
        int x , y ;
        cin>>x>>y;
        adj[x].push_back( y );
        adj[y].push_back( x);
     }
     vector<int >dis( n+1 , 0);
     dfs(  1 , 1 , adj , dis , 0);
     int node = max_element( dis.begin() , dis.end() )-dis.begin();
     vector<int >dis2( n+1, 0);
     dfs( node, node , adj, dis2, 0);
     node = max_element( dis2.begin() , dis2.end() )-dis2.begin();
     vector<int> dis3( n+1 , 0 );
     dfs( node, node, adj, dis3 ,0);
     vector<int > ans( n+1);
     for( int i=1 ;i<=n  ;i++){
        ans[i] = max( dis2[i] , dis3[i]);
     }

     map<int , int >mp ;
     for( int i=1 ;i<=n ;i++)mp[ans[i]]++;
     int cnt  =1 ;
     for( int i=1 ;i<=n  ;i++){
        cout<<min( cnt , n)<<" ";
        cnt += mp[i];
     }
return 0;
}