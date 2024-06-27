#include<bits/stdc++.h>
using namespace std;
int count ( int ind  , int sum , vector< int > & coins , vector< vector< int >> &dp  ){
    if( sum  ==0 ) return 1 ;
    if( ind<0 ) return 0 ;
    if( dp[ind][sum] != -1 ) return dp[ind ][sum];
    int nottake = count ( ind-1  , sum  , coins  , dp);
    int take = 0 ;
    if( sum - coins[ind] >= 0 ) take =  count( ind , sum - coins[ind] , coins  , dp );

    return dp[ind][sum ] =  nottake  + take;
}
int  main (){
     int n , sum ;
     cin>>n>>sum ;
     vector< int >  coins(n) ;
     vector< vector< int >> dp( n , vector< int >  ( sum+1 , -1 ));
     for( int i=0 ;i< n  ;i++){
        cin>> coins[i];
     }
     cout<<count( n-1 , sum  , coins  , dp );
return 0;
}