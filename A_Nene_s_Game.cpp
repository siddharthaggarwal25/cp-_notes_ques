#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while( t--){
        int k , q ;
        cin>>k>>q;
        vector< int > v( k);
        for( int i=0 ;i< k ;i++) cin>>v[i];
        int value  = v[0]-1;

        while( q--){
            int a ;
            cin>>a ;
            int ans = min(  value  , a);
            cout<<ans<<" ";
        }
        cout<<endl;
     }
return 0;
}