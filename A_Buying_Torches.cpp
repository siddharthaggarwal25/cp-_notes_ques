#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main (){
       int t ;
       cin>>t ;
       while( t--){
        int x , y, k ;
         cin>>x>>y>>k;


          int need = k*y + k ;
     
          int op  = (  (need  -1  + x-2) /( x-1));
          

          cout<<op + k <<endl;
       }

return 0;
}