#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t ;
     cin>>t ;
     while( t--){
        int n ;
        cin>>n  ;
        vector<int >  a (n), b ( n );
        for( int i=0  ;i< n  ;i++)cin>>a[i]; 
        for( int i=0  ;i< n  ;i++)cin>>b[i]; 
         int l1 = 0 , l2 =0 , h1 = n-1 , h2 = n-1 ;
         bool  flag = true     ;
         for( int i=0 ;i< n  ;i++){
              if( a[l1] != b[l2] && a[l1]  != b[h2]){
                flag = false;
                break ;
              }else if( a[h1]  != b[l1] && a[h1] != b[h2]){
                flag = false;
                break ;
              }else if( a[l1] == b[l2]){
                l1++ ;
                l2 ++;
              }else if( a[l1] == b[h2]){
                l1++ ;
                h2--;
              } 
         }

         if  ( flag )cout<<"Bob"<<endl;
         else cout<<"Alice"<<endl;
     }
return 0;
}