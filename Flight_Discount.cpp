#include<bits/stdc++.h>
using namespace std;
int  main (){
     int n , m ;
     cin>>n>>m ;
     vector<pair< pair< int , int > , int  >>edges;
     vector< vector< pair< int , int >>>adj( n+1);
     for( int i=0 ;i< m  ;i++){
        int x  , y , z ;
        cin>>x>>y>>z;
        adj[x].push_back( { y , z});
        edges.push_back( { { x , y} , z});
     }
     vector< int >dis( n+1 , 1e9);
     priority_queue< pair< int , int > , vector<pair< int , int >> , greater<pair<int , int >>>pq ;
     pq.push ( { 0 , 1});
     dis[1]=0;
     while( !pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for( auto child : adj[node]){
            if( dis[child.first] > dist + child.second ){
                dis[child.first] = dist + child.second;
                pq.push( { dis[child.first ] , child.first});
            }
        }
     }
     int ans = INT_MAX;
     for( auto  i : edges){
        int u = i.first.first;
        int v = i.first.second;
        int z = i.second;
        ans  = min ( ans  ,  dis[n] - dis[v] + dis[u] + z/2 );
     }
     cout<<ans<<endl;
    

return 0;
}