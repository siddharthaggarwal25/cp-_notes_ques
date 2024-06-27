#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main (){
     int n , m ;
     cin>>n>>m ;
     vector< vector< pair<int , int > >>adj( n+1);
     for( int i=0 ;i< m  ;i++){
        int x , y  , w;
        cin>>x>>y >>w;
        adj[x].push_back( { y , w} );

     }     
     vector< int > dis( n+1 , 1e9 );
     dis[1] =0 ;
     priority_queue< pair< int , int > , vector<pair< int , int >> , greater< pair<int , int >>>pq ;
     pq.push( { 0 , 1 });
     while( !pq.empty()){
        int w = pq.top().first;
        int  node = pq.top().second;
        pq.pop();
        for( auto  child : adj[node]){
            if( dis[child.first] >  w + child.second ){
                dis[child.first] = w + child.second;
                pq.push( {  dis[child.first] , child.first});
            }
        }

     }
     for( int i=1  ;i<=  n;i++){
        cout<<dis[i]<<" ";
     }
return 0;
}