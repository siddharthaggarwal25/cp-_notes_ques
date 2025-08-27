#include<bits/stdc++.h>
using namespace std;
int  main (){
      int t ;
       cin>>t ;
        while( t--){
             int  n ;
              cin>>n ;
              unordered_map<int  , int > mp ;
              for( int i= 0 ;i< n ;i++){
                 int x  ;
                 cin>>x ;
                 mp[x]++;
              }
              bool  ans  =false ;
              for( auto it : mp){
                 if( it.second  >= 2) ans  = true ;
              }
              if( ans)cout<<"YES"<<endl;
              else cout<<"NO"<<endl;
        }
return 0;
}