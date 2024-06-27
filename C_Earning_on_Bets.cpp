#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main (){
     int t;
     cin>>t ;
     while( t--){
        int n ;
        cin>>n ;
        vector< int > k(n);
        for( int i=0 ;i< n  ;i++){
            cin>>k[i];
        }
        int q=1 ;
        for( int i=0 ;i<n  ;i++){
            int a = __gcd(q , k[i] );
            q =  ( q*k[i])/a;
        }

        vector< int > test( n );
        int sum =0 ;
        for( int i=0 ;i<n  ;i++){
            test[i] = q/k[i];
            sum +=test[i];
        }

        if( sum >= q){
            cout<<-1<<endl;
        }else{
            for( int i=0 ;i< n  ;i++){
                cout<<test[i]<<" ";
            }
            cout<<endl;
        }


     }
return 0;
}