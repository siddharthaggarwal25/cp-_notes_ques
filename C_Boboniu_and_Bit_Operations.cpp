#include<bits/stdc++.h>
using namespace std;
int dp [ 201][1000];
int solve ( int ind , int newc, int n , int m , vector<int > & a , vector< int > & b){
    if( ind == n )return newc ;
    if( dp[ind][newc] != -1  )return dp[ind][newc];
    int ans  = 1e9 ;
    for( int i=0  ;i< m  ;i++){
        int val= b[i ];
        int cur = a[ind] ;
        int q =( val&cur);
        int c = newc;
        for( int i =  9  ; i>=0 ;i--){
            if( q & (1<<i)  ){
                c = c | ( 1<<i);
            }  
        }
         ans = min(ans  , solve( ind+1 , c  , n , m , a , b ));
    }
    return  dp[ind][newc]=  ans ; 
}
int  main (){
     int n ,  m ;
     cin>>n>>m ;
     vector<int >  a( n ) , b( m );
     memset( dp , -1, sizeof( dp ));
     for( int i=0 ;i< n  ;i++)cin>>a[i];
     for( int i=0 ;i< m  ;i++)cin>>b[i];
    int ans = solve (  0  , 0 , n , m , a, b );
    cout<<ans<<endl;
return 0;
}