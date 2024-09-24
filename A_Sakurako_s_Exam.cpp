#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t  ;
     cin>>t ;
     while( t--){
        int  a , b ;
        cin>>a>>b  ;
        if( a%2 ==1 )cout<<"NO"<<endl;
        else {
            if( b%2 == 0 ){
                cout<<"YES"<<endl;
            }else{
                b=1  ;
                if(  a>= 2)cout<<"YES"<<endl;
                else  cout<<"NO"<<endl;
            }
        }
     }
return 0;
}