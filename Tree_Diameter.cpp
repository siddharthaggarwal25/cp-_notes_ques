#include <bits/stdc++.h>
using namespace std;
vector<int > height ;
vector<vector<int >> adj ;
void dfs( int node ,int parent , int h  ){
     height[node] = h;
     for( auto  child  : adj[node] ){
         if( child  == parent )continue;
         dfs( child , node, h+1);
     }
}
int main()
{
    int n;
    cin >> n;
    adj.resize( n+1 );
    height.resize( n+1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs ( 1  , -1 , 0);
    int firstnode  ;
    int maxi  =-1 ;
     for( int i =1 ;i<= n  ; i++){
         if( height [i] >maxi  ) {
             firstnode = i ;
             maxi = height[i];
         }
     }


     dfs( firstnode , -1  ,0   );
     maxi =0 ;
     for( int i =1  ;i<= n ;i++){
         if( height[i] > maxi )maxi = height[i];
     }

     cout<<maxi;


    return 0;
}