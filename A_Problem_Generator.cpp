#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t ;
     while( t--){
         int n , m;
         cin>>n>>m ;
         string s ;
         cin>>s;
         map< char , int > mp;
         for(  int i=0 ;i< n  ;i++){
            mp[s[i] -'A']++;
         }
         int ans  = 0 ;
         for( int i  = 0 ;i< 7  ;i++){
            if( mp[i] <m  ){
                ans  += m- mp[i];
            }
         }
         cout<<ans<<endl;

     }
return 0;
}