#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t ;
     while( t--){
        int n , k ;
        cin>>n>>k ;
        int odd = ( n+1)/2 -  ( n-k +1)/2;
        if( odd%2 )cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
     }
return 0;
}