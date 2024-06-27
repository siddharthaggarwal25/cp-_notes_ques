#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t ;
     cin>> t;
      while( t--){
        int a , b , c;
        cin>>a>>b>>c ;
        int tents =a ;
        tents +=b/3;
        b= b%3 ;
        if( b + c < 3 && b!=0){
            cout<<-1<<endl;
        }else{
            b= b+c;
            tents +=  b/3;
            b= b%3;
            if( b>0){
              tents++;
            }
            cout<<tents<<endl;
        }

         
      }
return 0;
}