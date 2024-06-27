#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t ;
     cin>>t;
     while( t--){
        int a ,b ,c , d ;
        cin>>a>>b>>c>>d;
        int ans =0 ;

        if(  a%2==1 && b%2==1 && c%2==1) ans++;
        int one = a/2;
        int two = b/2;
        int three = c/2;
        int four  = d/2 ;
         ans  += one + two + three+ four;


        cout<<ans<<endl;
     }
return 0;
}