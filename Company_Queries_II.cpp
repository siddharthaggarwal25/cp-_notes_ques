// using binary lifting 
#include<bits/stdc++.h>
using namespace std;
int N= 2e5 +5 ;
vector < vector<int> > adj ( N);
vector<int> depth(N);
vector< vector<int> > up ( N , vector<int > (20)); 
void dfs( int   node , int par){
    up[node][0] = par;
    for( int i= 1 ;i< 20  ;i++){
        int halfParent = up[node][i-1];
        up[node][i] = up[halfParent][i-1];
    }x  
     for( auto child : adj[node]){
        depth[child ]= depth[node] + 1;
        dfs(  child  , node);
     }
}
int kthparent( int node  , int k) {
    for( int i=19 ;i>= 0 ;i--){
        if( k&(1<<i)) node = up[node][i];
    }
    return node ;
}
int leastCommonAncestor ( int a  , int b  ){
    if( depth[b] > depth[a])  swap( a , b );
    int climb  = depth[a] - depth[b];
    a = kthparent( a , climb );
    if(a== b) return a ;
    for( int i=19 ;i>=0  ; i--){
        if( up[a][i] == up[b] [i ]) continue;
        a= up[a][i];
        b= up[b][i];
    }
    return up[a][0];
}

int  main (){
     int n , q ;
     cin>>n>>q;
     for( int i=2  ;i<=  n ;i++){
        int a ;
        cin>>a;
        adj[a].push_back( i);
     }
     dfs( 1 ,0 );
     while( q--){
        int a , b ;
        cin>>a>>b ;
        cout<<leastCommonAncestor( a  , b)<<endl;
     }


return 0;
}