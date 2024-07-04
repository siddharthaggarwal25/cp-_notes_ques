#include<bits/stdc++.h>
using namespace std;
#define int long long 
int solve( int ind  , int getVitamins , vector<pair<int , string >> & v  , vector<vector<int >>& dp ){
       if( getVitamins == 7)return 0 ;
       if( ind  == v.size()) return 1e9 ;
       if( dp[ind][getVitamins]!= -1 )return dp[ind][getVitamins ];
       int nottake =  solve ( ind +1 , getVitamins ,  v  , dp);
       int vit  = getVitamins;
       for( auto it  : v[ind].second){
          if( it  == 'A') vit  = vit  | 1;
          else if( it  =='B')vit  = vit |2;
          else  vit = vit  |4;  
       }  
       int take = v[ind].first + solve ( ind+1 , vit ,  v , dp );
       return  dp[ind][ getVitamins] =min ( take , nottake  );
}
int32_t   main (){
     int n ;
     cin>>n ;
     vector< pair<int , string >>v( n );
     for( int i=0 ;i< n  ;i++){
         int x  ;
         string s ;
         cin>>x>>s;
         v[i] = { x , s };
     }
     vector< vector<int >>dp ( n , vector<int > (8 , -1));
    int ans  = solve(  0 , 0 , v , dp );
    if( ans == 1e9  ) cout<<-1<<endl;
    else cout<<ans<<endl;
return 0;
}