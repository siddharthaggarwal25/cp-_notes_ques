#include<bits/stdc++.h>
using namespace std;
int  main (){
       int t;
       cin>>t ;
       while( t--){
         int a , x, y ;
         cin>>a>>x>>y ;
         if( x>y)swap ( x , y);
         
        if( a>=x  && a<=y)cout<<"NO"<<endl;
        else  cout<<"YES"<<endl;

       }
return 0;
}