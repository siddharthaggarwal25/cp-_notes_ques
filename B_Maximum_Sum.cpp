#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main (){
       int t ;
       cin>>t ;
       while( t--){
         int n , k;
         cin>>n>>k;
         int ans  =0 ;
         vector<int > v( n);
          for( int i =0  ;i<n ;i++)cin>>v[i] , ans+= v[i];
          sort( v.begin() , v.end());
          int low  =0;
          int high  = n-1;
          cout<<ans<<endl;

          for( int i=0 ;i<k ;i++){
             if( low != high  && v[low]+ v[low+1] < v[high]){
                ans -= ( v[low] + v[low+1]);
                low+=2 ;

             }else{
                  ans -=v[high];
                  high --;
             }
          }
          cout<<ans<<endl;
       }
return 0;
}