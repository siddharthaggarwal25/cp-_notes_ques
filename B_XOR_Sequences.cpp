#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t ;
     while( t--){
        int x , y ;
        cin>>x>>y ;
        int a = x^y;
        int ind =0 ;
        for( int i=0 ;i<32 ;i++){
            if( (a>>i &1) == 1 ){
                ind = i ;
                break ;
            }
        }
        cout<< ( 1<<ind)<<endl;
     }
return 0;
}