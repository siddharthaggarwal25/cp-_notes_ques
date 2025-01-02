#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t   main (){
     int t ;
     cin>>t ;
     while ( t--){
         int n  , k ;
         cin>>n>>k ;
         vector<int>  v ( n);
         for( int i=0 ;i< n  ;i++)cin>>v[i];
         sort( v.begin() , v.end());

         int count = k ;
         for( int i =0  ;i< n  ;i++){
            int value = v[i] ;
            if(  v[i]*( n-i) >= k )break ;
            else {
                count++ ;
                k = k- v[i];
            }
         }
         cout<<count<<endl;
         
     }
return 0;
}