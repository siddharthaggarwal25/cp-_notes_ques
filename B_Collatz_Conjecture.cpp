#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t ;
     while( t--){
        int x ,  y , k ;
        cin>>x>>y>>k  ;
        int rem= y -x%y;
        while(  k >= rem){
             k= k- rem ;
             x = x+ rem ;
             while( x%y ==0 ){
                x = x/y;
             }
              rem  = y- x%y;
              if( x == 1){
                 k= k%rem;
                  x+=k ;
                  k=0 ;
                  break ;
              }
        }
        x += k ;
        cout<<x<<"\n";
     }
return 0;
}