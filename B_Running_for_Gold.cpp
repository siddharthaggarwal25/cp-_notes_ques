#include<bits/stdc++.h>
using namespace std;
int  main (){
      int  t ;
      cin>>t ;
      while( t--){
         int n ; 
         cin>>n ;
         vector<vector<int >>v(n);
         for( int i =0  ;i< n  ;i++){
            for( int  j=0 ;j< 5 ;j++){
                int a ;
                cin>>a ;
                v[i].push_back( a);
            }
         }

         vector<vector<int >>  adj ( n);
         for( int i=0 ;i< n ;i++){
            for(  int j= i+1  ; j< n  ;j++){
                  int count =0 ;
                  for( int k=0 ;k< 5  ;k++){
                     if( v[i][k] < v[j][k])count++;
                  }
                  if( count  >=  3)adj [j].push_back( i);
                  else adj[i].push_back( j);
            }
         }
         queue<int > q ;
         vector<int > inDegree(n );
         for( int i=0 ;i< n  ;i++){
            for(  auto it  : adj[i]){
                inDegree[it]++;
            }
         }

         for( int i=0 ;i< n ;i++){
            if( inDegree[i] ==0 )q.push( i);
         }

         vector<int > ans ;

         while( !q.empty()){
              int node = q.front() ;
              q.pop();
              ans.push_back( node);

              for( auto it  : adj[ node]){
                inDegree[it]-- ;
                if( inDegree[it] ==0  ) q.push( it );
              }
         }

         if( ans.size() != n )cout<<-1<<endl;
         else cout<<  ans[n-1]+1<<endl;
      }
return 0;
}