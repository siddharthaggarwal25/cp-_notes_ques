#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t ;
     cin>>t ;
     while( t--){
        int n , m , k ;
        cin>>n>>m>>k; 
        int a = min ( n  , k );
        int b = min ( m , k );
        cout<<a*b<<endl;
     }
return 0;
}