#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t   main (){
       int t ;
        cin>>t ;
         while( t--){
              int x , y ;
               cin>>x>>y ;
               if( x== y)cout<<-1<<endl;
               else cout<< (1LL<<40) -max( x , y )<<endl;
         }
return 0;
}