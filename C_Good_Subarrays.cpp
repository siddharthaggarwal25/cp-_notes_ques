#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main (){
     int t ;
     cin>>t  ;
     while( t--){
        int n ;
        cin>>n ;
        string s;
        cin>>s ;
        vector<int > v( n );
        for( int i=0 ;i< n  ;i++){
            v[i] =    ( s[i] - '1');
        }

        int count  =0 ;
        int temp =0 ;
        map< int , int>presums;

        for( int i=0 ;i< n  ;i++){
            temp += v[i];
            if( temp == 0 )count++;
            count +=presums[temp];
            presums[temp]++;
        }
    
        cout<<count<<endl;
     }
return 0;
}