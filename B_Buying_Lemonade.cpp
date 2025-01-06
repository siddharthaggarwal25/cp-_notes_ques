#include<bits/stdc++.h>
using namespace std;

int   main (){
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
            long long int  value = v[i] ;
            if(  value *( n-i) >= k )break ;
            else {
                count++ ;
                k = k- v[i];
            }
         }
         cout<<count<<endl;
         
     }
return 0;
}

