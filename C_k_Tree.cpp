#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 +7 ;
int dp [10000][2];
int solve( int sum , bool isgreater , int n , int k ,int d ){
    if( sum >n )return 0;
    if( sum == n ){ 
        if( isgreater)return 1 ;
        return 0 ;
    }
    if( dp[sum][isgreater] != -1 )return dp[sum][isgreater];
    int ans =0 ; 
    for( int i=1  ;i<= k ;i++){
        ans+=  solve( sum +i , ( isgreater || i>=d) , n , k , d);
        ans = ans%mod ;
    }
    return  dp[sum][isgreater] = ans%mod ; 


}
int  main (){
     int n , k ,d ;
     cin>>n>>k>>d ;
     memset( dp , -1 , sizeof( dp ));
     cout<<solve( 0 , false , n , k , d)<<endl;;
return 0;
}