#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t ;
     cin>>t ;
     while( t--){
         long long int n ;
         cin>>n  ;
         int ans  = 1 ;
         while( n > 3){
            ans = ans*2 ;
            n = n/4 ;
         }
         cout<<ans<<endl;
     }
return 0;
}