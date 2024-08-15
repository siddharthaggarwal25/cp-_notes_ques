#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main (){
     int t ;
     cin>>t ;
     while( t--){
        int n ;
        cin>>n ;
        vector<int > order( n ) ;
        for( int i=0 ;i < n  ;i++)cin>>order[i] ;

         vector<int >  temp ( n+2 , 0 );
        
         temp[order[0]] = 1;
        
         bool flag = true  ;
         for( int i= 1; i< n ;i++){
             if( temp[order[i] +1] ==1  ||  temp[order[i] -1]==1){
                temp[order[i]] = 1;
                continue;
             }
             flag = false;
             break ;
         }

         if( flag )cout<<"YES"<<endl;
         else cout<<"NO"<<endl;
     }
return 0;
}