#include<bits/stdc++.h>
using namespace std;
#define int long long 
int maxh( int ind  , int n  , vector< vector< int >> & v , int last , vector< vector<int >> &dp ){
    if( ind  == n ) return 0 ;
    if( dp[last +1][ind] !=-1 ) return dp[last+1 ][ind ];
    int nottake  = maxh( ind+1 , n , v , last  , dp  );
    int  take1 = 0  ;
    int  take2 = 0  ;
    if( last   == -1  ||  last == 1)   take1  =  v[1][ind] + maxh( ind +1 , n , v ,  0 , dp    );
    if( last  == - 1  ||  last ==0 ) take2  =    v[0][ind ] +   maxh( ind+1 , n , v , 1   , dp );
     return  dp[last+1 ][ind] =  max( nottake , max( take1 , take2));
}
int32_t  main (){
     int n ;
     cin>>n ;
     vector< vector< int >> v( 2  , vector< int > ( n));
     vector< vector<int  >> dp ( 3  , vector< int > ( n ,-1 ) );
     for( int i =0  ;i< n  ;i++) cin>>v[0][i];
     for( int i =0  ;i< n  ;i++) cin>>v[1][i];
     cout<<maxh( 0  , n  , v  , -1  , dp );
return 0;
}