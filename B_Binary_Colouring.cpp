#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t ;
     cin>>t ;
     while( t--){
        int n ;
        cin>>n;
         vector< int >  v( 33 , 0 );
         for( int i=0 ;i<32  ;i++){
            if( n>>i & 1) v[i] =1 ;

         }
         for( int i=1  ;i<32 ;i++){
            if( v[i-1] == 1  && v[i]==1){
                v[i-1] = -1 ;
                v[i] = 0;
                v[i+1] ++; 
            }

            if( v[i] == 2){
                v[i] = 0 ;
                v[i+1] ++;
            }
         }
         cout<<32<<endl;
         for( int i=0 ;i< 32 ;i++){cout<<v[i]<<" ";}
         cout<<endl;

     }
return 0;
}