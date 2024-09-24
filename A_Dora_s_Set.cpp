#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t ;
     while ( t--){
         int l , r ;
         cin>>l>>r ;
         int cnt  =0 ;
         for( int i= l  ;i<= r ;i++){
            if(i%2 == 1)cnt ++;
         }
         cout<< ( cnt/2) <<endl;
     }
return 0;
}