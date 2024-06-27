#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin >>t ;
      while( t--){
        int n  ;
        cin>>n  ;
        vector< int >  x ( n);
        for( int i=1 ;i< n ; i++){
            cin>>x[i];
        }
         vector< int > ans ( n);
         ans [0] = 501;
         for( int i=1  ;i< n  ;  i++){
            ans [i] = ans [i-1] + x[i];
         }

         for( int i=0 ;i<  n  ;i++){
            cout<<ans[i]<<" ";
         }
         cout<<endl;
      }
return 0;
}