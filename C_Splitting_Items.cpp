#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main (){
     int t ;
     cin>>t ;
     while  ( t--){
         int n , k ;
         cin>>n>>k ;
         vector<int >  arr( n);
         for( int i=0 ;i< n  ;i++){
            cin>>arr[i];
         }
         sort( arr.begin() , arr.end() , greater<int>() );
        
         int a = 0 ;
         int b =0 ;
         for( int i=0 ;i< n  ;i++){
              a += arr[i] ;
              i++;
              if( i<n){
                  int diff = arr[i-1] - arr[i] ;
                  if( k > diff){
                      b += arr[i-1] ;
                      k = k-diff ;
                  }else{
                     b  += arr[i] + k;
                     k=0 ;
                  }
              }
         }

         cout<< max( (long long ) 0 , a-  b)<<endl;
     }
return 0;
}