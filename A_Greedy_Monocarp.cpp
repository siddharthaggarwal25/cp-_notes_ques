#include<bits/stdc++.h>
using namespace std;
int  main (){
      int t ;
      cin>>t ;
      while( t--){
         int n , k ;
         cin>>n>>k ;
         vector<int > v( n );
         for( int i=0 ;i<  n  ;i++)cin>>v[i];
         sort( v.begin() , v.end() , greater<int >());
         int ans = 0 ;
         for( int i=0 ;i< n  ;i++){
            if( v[i] < k){
                 k = k- v[i];
            }else if( v[i] > k ){
                ans  = k ;
                k=0 ;
                break ;
            }else {
                ans =0 ;
                k=0 ;
                break ;
            }
         }

         ans += k ;
         cout<<ans<<endl;

      }
return 0;
}