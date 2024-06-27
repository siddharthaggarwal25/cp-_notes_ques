#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t ;
     cin>>t;
     while( t--){
        int a , b , c ;
        cin>>a>>b>>c;
         if( c>b && b>a ){
            cout<<"STAIR"<<endl;
         }else if( b>c && b>a){
            cout<<"PEAK"<<endl;
         }else{
            cout<<"NONE"<<endl;
         }
     }
return 0;
}