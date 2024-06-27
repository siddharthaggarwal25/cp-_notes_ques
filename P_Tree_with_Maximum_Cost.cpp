#include<bits/stdc++.h>
using namespace std;
vector< int > weight;
vecotr< vector< int >> adj;
int  main (){
     int n ;
     cin>>n;
     weight.resize( n+1);
     adj.resize(n+1);
     for( int i=1  ;i<= n ;i++)  cin>>weight[i];
     for( int i=0; i<n- 1   ;i ++){
        int u ,v ;
        cin>>u>>v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
     }
     
return 0;
}