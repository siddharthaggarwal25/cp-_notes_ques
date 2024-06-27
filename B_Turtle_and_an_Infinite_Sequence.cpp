#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t ;
     while( t--){
        int n  , s ;
        cin>>n>>s ;
        if( s== 0){
            cout<<n<<endl;
            continue;
        }
        int ind =-1  ;
        for( int i=31 ; i>=0  ;i--){
            if( s>>i &1) {
                ind = i ;
                break;
            }
        }
        
        for( int i= ind  ;i>=0 ;i--){
            n = n|( 1<<i);
        }
        cout<<n<<endl;

     }
return 0;
}