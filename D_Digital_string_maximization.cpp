#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t ;
     cin>>t ;
     while( t--){
         string s ;
         cin>>s ;
         int n = s.length() ;
          for( int i =0  ;i<  n  ;i++){
                 int value = s[i]-'0';
                 int ind = i;
                for( int j= 0  ;j<  10  ;j++){
                    if(  ( i+ j ) < n){
                        if( value < ( (s[i+ j] -'0') - j)) {
                            value =( s[i+ j]-'0') - j ;
                            ind  = i+ j ; 
                        } ;
                    }
                }
                for( int k = ind  ;k>i  ;k--  ){
                    s[k] = s[k-1];
                }
                s[i] = '0' + value  ;
               
          }            
          cout<<s<<endl;
     }
return 0;
}