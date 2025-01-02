#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t ;
     cin>>t ;
     while( t--){
         int n , d, k,   a, b;
         cin>>n>>d>>k ;
         vector<int >  start( n+1) , end( n+1);
         for( int i=0 ;i< k  ;i++){
            cin>>a>>b ;
            start[a]++;
            end[b]++;
         }
         for( int i=1 ;i<= n  ;i++ ){
            start[i] += start[i-1];
            end[i] += end[i-1];
         }

         int mom = 0  , bro  = 0  , least =1e9  , most =0 ;

         for( int i =d ;i<=n ;i++){
            int cur  = start[i] - end[i-d];
             if( cur > most ) most = cur , bro  = i -d+1;
             if( cur < least ) least = cur , mom  = i-d+1  ;
         } 
         cout<<bro <<" " << mom <<endl;
     }
return 0;
}