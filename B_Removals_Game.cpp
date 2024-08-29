#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t ;
     cin>>t ;
     while( t--){
        int n ;
        cin>>n  ;
        vector<int >  a (n), b ( n ) , c( n);
        for( int i=0  ;i< n  ;i++)cin>>a[i]; 
        for( int i=0  ;i< n  ;i++){
            cin>>b[i];
            c[i]= b[i];
        }
        reverse( c.begin()  , c.end());
        if( a== b  || a==c){
            cout<<"Bob"<<endl;
        }else{
            cout<<"Alice"<<endl;
        }
     }
return 0;
}