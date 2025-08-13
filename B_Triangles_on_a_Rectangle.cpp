#include<bits/stdc++.h>
using namespace std;
#define int long long 
int solve( ){
    int k ;
    cin>>k ;
    int val =0  ;
    for( int  i =0  ;i<k  ;i++){
        int x ;
        cin>>x;
         if( i==0)  val  -= x;
         if( i == k-1)val += x;
    }
    return val  ;
}
int32_t  main (){
       int t;
       cin>>t;
       while( t--){
         int w  , h  ;
         cin>>w>>h ;
         vector<int > x0 , x1 , y0  , y1 , val ;

        
        int ans  = 0  ;
        ans  = max(  solve()*h  , solve()*h);
        ans = max( ans , solve( )*w);
        ans  = max( ans , solve( )*w);
        cout<<ans<<endl;
         
         
       }
return 0;
}