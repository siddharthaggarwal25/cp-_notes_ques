#include<bits/stdc++.h>
using namespace std; 
int mod = 1e9 + 7 ;
int count ( int sum  , vector< int > & dp ){
    if( sum  == 0 )  return 1  ; 
    if( dp[sum] != -1 ) return dp[sum];
    int ans  = 0 ; 
    for( int i=1 ;i<= 6  ;i++){
        if( sum - i >= 0 )  ans  = ((ans + count ( sum -i   , dp )) %mod);
    }
    return  dp[ sum  ] = ans%mod  ; 

}
int  main (){
     int n ;
     cin>>n ;
     vector< int >  dp( n+1 , -1 );
     cout<<count ( n , dp );

return 0;
}