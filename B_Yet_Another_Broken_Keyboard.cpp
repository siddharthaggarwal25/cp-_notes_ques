#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main (){
     int n , k ;
     cin>>n>>k ;
     string s ;
     cin>>s ;
    unordered_map<char , int > mp ;
     for( int i=0 ;i< k ;i++){
        char x ;
        cin>>x ;
        mp[x]  = 1;
     }
     int ans  =0 ;
     for( int i=0 ;i< n  ;i++){
         
          int cnt  =0 ;
          while( i<n && mp[s[i]] == 1){
              cnt ++;
              i++;
          }
          ans  = ans +  (cnt*( cnt+1))/2;
     }
     cout<<ans<<endl;
return 0;
}