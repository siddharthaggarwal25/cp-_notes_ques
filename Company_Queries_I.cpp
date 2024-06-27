#include <bits/stdc++.h>
using namespace std;
const int  N  =  2e5 +5 ;
vector< vector <int > > adj( N  );
vector< int > depth( N , 0);
vector< vector<int> >  up ( N , vector< int > ( 20 , 0)); 

void dfs ( int node , int  parent ){
    up[node][0] = parent ;
    for( int i=1 ;i<20 ;i++){
        int halfParent = up[ node][i-1];
        up[node][i] = up[halfParent][i-1];
    }
    for( auto child : adj[node]){
        // if( child == parent ) continue; 
        depth[child ] = depth[node ] +1 ;
        dfs( child , node ); 
    }
}
int kthparent ( int node , int k ){
    for( int i=19 ;i>=0 ;i--){
        if( k&( 1<< i ))  node = up[node][i];
    }
    return node;
}
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n ; i++)
    {
        int a;
        cin >> a;
        adj[a].push_back(i);
        // adj[i].push_back(a);
    }
    dfs( 1 , 0 );
    while( q--){
        int node , k ;
        cin>>node>>k ;
        int ans = kthparent(node , k );
       if( ans ==0){
        cout<<-1<<endl;
       }else {
        cout<<ans<<endl;
       }
    }



    return 0;
}