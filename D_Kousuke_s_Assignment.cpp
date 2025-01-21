#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t   main (){
      int t ;
      cin >> t;
       while( t--){ 
         int n ;
         cin>>n ;
          vector< int >v  ( n );
          for( int i=0 ;i< n  ;i++)cin>>v[i];
          map<int , int >mp ;
          int ans  =0 ;
          int value  =0 ;
          mp[0]=1 ;
          for( int i=0 ;i< n  ;i++){
               value +=  v[i];
               if( mp[ value ]== 1 ){
                mp.clear();
                value =0 ;
                mp[0] = 1;
                ans++;
               }else{
                 mp[value] = 1;
               }
          }
          cout<<ans<<endl;
       }
return 0;
}