#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main (){
     int t;
     cin>>t ;
     while( t--){
        int n ;
        cin>>n ;
        vector< int > v( n );
        for( int i=0 ;i< n  ;i++){
            cin>>v[i];
        }
        vector< int > prefix( n );
        prefix[0]= v[0];
        for( int i=1; i< n  ;i++){
            prefix[i] = prefix[i-1] + v[i];
        }
        int largest = 0 ;
        int cnt  = 0 ;
        for( int i=0 ;i< n ;i++){
            int prefixsum = prefix[i];
            if( v[i] > largest){
                largest = v[i];
            }

            if( prefixsum- largest == largest)cnt ++;
        }
        cout<<cnt<<endl;
     }
return 0;
}