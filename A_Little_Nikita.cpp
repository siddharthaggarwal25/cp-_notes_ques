#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t ;
     while( t--){
        int n , m ;
        cin>>n>>m ; 
        if( m > n  ){
            cout<<"NO"<<endl;
        }else{
            int diff = n- m; 
            if( diff%2 == 0 ){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
     }
return 0;
}