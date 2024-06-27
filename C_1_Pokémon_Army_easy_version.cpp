#include<bits/stdc++.h>
using namespace std;
#define int long long 
int count( int  ind  , vector< int  > & v   , int  c , vector< vector<int >> & dp   ){
    if( ind  == v.size()) return 0 ;
    if( dp[ind][c] !=-1 ) return dp[ind][c];
    int nottake  =  count ( ind+1  , v , c , dp );
    int take ;
    if( c == 1) take  = v[ind  ] + count ( ind +1   , v , 0   , dp);
    else  take  = -v[ind] + count( ind+1  ,  v  , 1 , dp);
    return  dp[ind ][c]=max ( nottake , take  ) ;
}
int32_t   main (){
     int t ;
     cin>>t ;
     while(t--){
         int n , q ;
         cin>>n>>q ;
         vector< int > v( n ) ;
         vector< vector< int > > dp( n , vector< int > ( 2  ,-1 ));
         for( int  i=0 ;i< n  ;i++) cin>>v[i];
         cout<<count( 0 , v  , 1  , dp )<<endl;;
     }
return 0;
}