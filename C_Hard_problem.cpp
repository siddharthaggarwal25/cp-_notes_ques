#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>> t ;
     while( t--){
         int m , a, b, c ;
         cin>>m>>a>>b>>c ;
         int total  = 0 ;
         total +=  min ( m ,a) + min ( m ,b ) ;
         total = min ( 2*m , total + c);
         cout<<total<<endl;
     }
return 0;
}