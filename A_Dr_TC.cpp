#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t   main (){
      int t;
       cin>>t ;
        while( t--){
             int n ;
              cin>>n ;  
              string s ; 
               cin>>s ;
                int ones = 0 ;
                 for( int i=0 ;i< n  ;i++){ 
                    if( s[i] == '1')ones ++;
                 }
                 cout<< ( n-1)*ones + ( n-ones)<<endl;
        }
return 0;
}