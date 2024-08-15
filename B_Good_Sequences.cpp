#include<bits/stdc++.h>
using namespace std;
int  main (){
     int n ;
     cin>>n ;
     map<pair<int , int > , int > mp ;
     vector<int  > a ( n ) , b( n);
     for( int i=0 ;i<n  ;i++)cin>>a[i];
     for( int i=0 ;i<n  ;i++)cin>>b[i];

     vector<vector<int >> adj( n+1);
     for( int i=0 ;i<n  ;i++){
        adj[a[i]].push_back( b[i]);
        adj[b[i]].push_back( a[i]);
        mp[{a[i] , b[i]}] = 1;
     }
     queue<int >  q ;
     vector<int >vis( n+1 , 0 );
     q.push( 0 );
     vis[0] = 1;
     int cnt = 0 ;
     while( !q.empty()){
        int node = q.front();
        q.pop();
        for( auto child  : adj [node]){
            if( vis[child ])continue;
            if( mp[{node , child }])cnt++;
            q.push( child );
            vis[child  ]=1 ;
        }
     }
     cout<<cnt<<endl;


return 0;
}