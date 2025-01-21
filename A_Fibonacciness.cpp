#include<bits/stdc++.h>
using namespace std;
int  main (){
      int t;
      cin>>t ;
       while( t--){
         int a , b, c, d ;
         cin>>a>>b>>c>>d ;
         int e = a+b ;
         int f = c-b ;
         int g = d-c ;

         if( e==f && e==g)cout<<3<<endl;
         else if( e==f || f==g || e==g)cout<<2<<endl;
         else cout<<1<<endl;
       }
return 0;
}