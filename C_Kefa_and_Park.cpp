#include <bits/stdc++.h>
using namespace std;
int m ;
void dfs( int node , vector< int > & vis  , vector< vector< int >> &adj , vector< int > & ans , vector<int > & cats ){
    vis[node] = 1;

    for( auto child : adj[node]){
        if( !vis[child ]){
            if( cats[child]){
                if( ans[node] > m ){
                    ans[child] = ans[node];
                }else{
                    ans[child]  = 1 + ans[node];
                }

            }else{
                if( ans[node] > m ){
                    ans[child] =  ans[node] ;
                }else{
                    ans[child] = 0 ;
                }
            }
            dfs( child , vis , adj  ,ans , cats  );
        }
    }
}
int main()
{
    int n;
    cin >> n >> m;
    vector<int> cats(n+1);
    for( int i=1 ;i<= n  ;i++)cin>>cats[i];
    vector< vector< int >> adj( n+1);
    for( int i=1  ;i<n  ;i++){
        int x , y;
        cin>>x>>y ;
        adj[x].push_back( y);
        adj[y].push_back( x);
    }
    vector< int > vis ( n+1 , 0 );
    vector< int >  ans ( n+1 , 0 );
    if( cats[1] == 1) ans[1] =1 ;
    vis[1]  =1 ;
    dfs( 1 , vis , adj ,ans  , cats  );
    int count =0 ;
    for( int i= 2;i<= n  ;i++){
        if( adj[i].size() == 1 ){
            if( ans[i] <= m  ){
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}