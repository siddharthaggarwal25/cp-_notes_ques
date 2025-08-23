#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main (){
      int t;
      cin>>t ;
       while( t--){
         int n , m;
         cin>>n>>m ;
         vector<int > v( n+1 , n+1);
         for ( int i =0 ;i<m ;i++){
             int a  , b ;
             cin>>a>>b ;
             if( a>b)swap( a, b);
             v[a] = min ( v[a] , b);
         }

         int Rmax = n+1 ;
         int ans =0 ;
        for( int i = n ; i>=1  ;i-- ){
             Rmax = min ( Rmax , v[i]);
             ans += Rmax-i ;
         }
         cout<<ans<<endl;
       }
return 0;
}