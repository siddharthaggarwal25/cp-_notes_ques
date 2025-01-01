#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t ;
     cin>>t ;
     while( t--){
         int n ;
         cin>>n ;
         vector<int > v( n);
         for( int i=0 ;i< n ; i++)cin>>v[i];

         int average = 0 ;
         for( int i=0 ;i< n  ;i++){
            average += v[i];
         }
         
         average = average/n ;
         
         int count =0 ;
         for( int i=0 ;i< n  ;i++){
            if( v[i] < ( average/2))count++;
         }

         if( count >  ( n/2))cout<<0<<endl;
         else {
            cout<<" still happy"<<endl;
         }
     }
return 0;
}