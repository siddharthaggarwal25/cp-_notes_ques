#include<bits/stdc++.h>
using namespace std;
int solve(  int ind  , int lastele  , vector<int >& arr , vector<vector<int >> &dp){
    if( ind == arr.size() )return 0 ;
    if( dp[ind][lastele] != -1)return dp[ind][lastele];
     int take = 0 ;
     if( arr[ind]%lastele ==0 ){
        take = 1+ solve( ind+1 , arr[ind] , arr  , dp);
     }
     int nottake = solve( ind+1  , lastele , arr , dp);
     return  dp[ind][lastele] =  max( take , nottake);
}
int  main (){
     int t ;
     cin>>t ;
     while( t--){
         int n ;
         cin>>n ; 
         vector<int > arr( n );
         for( int  i=0 ;i< n ;i++)cin>>arr[i];
         sort( arr.begin()  , arr.end());
         vector<vector<int > >dp( n , vector<int > ( arr[n-1] +1  , -1));
         int  ans  =solve( 0 , 1 , arr  , dp );
         cout<< n-ans<<endl;
     }
return 0;
}