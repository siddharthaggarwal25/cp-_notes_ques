#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t ;
      while( t--){
        int n ;
        cin>>n  ;
        int ans =1   ;
        int y = 1 ;
        for( int i=1 ;i< n  ;i++){
            if( (__gcd(n , i ) +i) > ans ){
                ans = __gcd( n  , i ) +i  ;
                y=i ;
            }
        }
        cout<<y<<endl;

      }
return 0;
}