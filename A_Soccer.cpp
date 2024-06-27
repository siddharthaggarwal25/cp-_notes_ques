#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t ;
     cin>>t ;
     while( t--){
        int x1 , y1  , x2 , y2 ;
        cin>>x1>>y1>>x2>>y2 ;

        if( x1< y1 && y2 < x2){
            cout<<"NO"<<endl;
        }else if( y1 <x1 && x2<y2){

            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
     }
return 0;
}