#include<bits/stdc++.h>
using namespace std;
int  main (){
      int t ;
      cin>> t;
       while( t--){  
         int n , m ;
         cin >>n >>m ;
         vector<vector<int >> v( n , vector<int > (m ));
         for( int i= 0 ;i< n  ; i++){
             for ( int j=0 ;j< m  ;j++)cin>>v[i][j];
         }

         bool ans  = true  ;
         for( int i=0 ;i< n  ;i++){
             sort ( v[i].begin() , v[i].end());

             for( int j =1;j<  m ;j++){
                   if( v[i][j] - v[i][j-1] != n)ans = false ;
             }
         }

         if ( ans ){
              vector<pair< int , int >> a ;
              for( int i =0 ;i<n ;i++){
                 a.push_back( {  v[i][0] , i+1 });
              }

              sort( a.begin() , a.end());
              for( auto it : a){
                cout<<it.second<<" ";
              }

              cout<<endl;

         }else{
            cout<<-1<<endl;
         }
          
       }
return 0;
}