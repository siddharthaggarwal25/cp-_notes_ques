#include<bits/stdc++.h>
using namespace std;
int  main (){
     int n , k ;
     cin>>n>>k
     vector<int >t( n ) , s( n );
     for( int i=0 ;i< n  ;i++) cin>>t[i];
     for( int i=0 ;i< n  ;i++) cin>>s[i];
     vector< int > prefix( n , 0 );
     int window =0 ;
     for( int i=0 ;i< k  ;i++){
        window += t[i];
     }
     p[0] = window ;
     for( int i=1  ;i< n-k  ;i++){
        p[i] = p[i-1]  - t[i-1] + t[i+k ]; 
     }
     for( int i= n-k  ;i< n  ;i++){
        p[i] = p[i-1]- t[i-1];
     }
return 0;
}