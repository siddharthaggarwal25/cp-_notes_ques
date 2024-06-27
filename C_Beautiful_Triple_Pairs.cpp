#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t   main (){
     int t;
     cin>>t ;
     while( t--){
         int n ;
         cin>>n ;
          vector< int > v( n );
          for( int i=0 ;i< n  ;i++){
            cin>>v[i];
          }
          int ans = 0 ;
          map<  pair< pair< int , int >, int > , int  >mp;
          for( int i= 0 ;i< n-2 ;i++){
            ans  += mp[{{ v[i] , v[i+1]} , 0} ] + mp[{{ v[i] , 0} , v[i+2]} ] + mp[{{ 0, v[i+1]} , v[i+2]} ]  -3*mp[{{ v[i] , v[i+1]} , v[i+2]} ];
            mp[{{ 0 , v[i+1]} , v[i+2]} ]++;
            mp[{{ v[i] , 0} , v[i+2]} ]++;
            mp[{{ v[i] , v[i+1]} , 0} ]++;
            mp[{{ v[i] , v[i+1]} , v[i+2]} ]++;
          }  
          cout<<ans<<endl;
     }
return 0;
}