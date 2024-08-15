#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t ;
     while( t--){
        int n ;
        cin>>n ;
        string a , b ;
        cin>>a>>b ;
        int a1 = INT_MAX;
        int b1 = INT_MAX;
        for( int i=0 ;i< n ;i++  ){
            if( a[i] == '1'){
                a1 = i ;
                break ;
            }
        }
        for( int i=0 ;i<n ;i++  ){
            if( b[i] == '1'){
                b1 = i ;
                break ;
            }
        }
        if(  b1 == INT_MAX){
            cout<<"YES"<<endl;
        }
         else if(  a1 == INT_MAX){
            cout<<"NO"<<endl;
        }
        else if( a1 > b1 ){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
     }
return 0;
}