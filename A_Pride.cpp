#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t  main (){
     int n ;
     cin>>n ;
     vector<int >v( n) ;
     int cnt =0 ;
     for( int  i=0 ;i< n ;i++){
        cin>>v[i];
        if( v[i] ==1)cnt++;
     }

     if( cnt != 0){
        cout<<n-cnt<<endl;
     }else {
         int ans = 1e16  ;
         for( int i=0  ;i< n  ;i++){
             int val = v[i];
             for( int  j = i+1  ;j< n ;j++){
                   val = __gcd( val , v[j]);
                   if( val == 1){
                    ans  = min ( ans   , n-1 + ( j-i) );
                   }
             }
         }
         if( ans  == 1e16)cout<<-1<<endl;
         else cout<<ans<<endl;
     }
     
return 0;
}