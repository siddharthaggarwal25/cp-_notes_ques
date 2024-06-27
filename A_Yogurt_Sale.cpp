#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while( t--){
        int n , a , b ;
        cin>>n>>a>>b;
        int ans =0 ;
        if( 2*a < b ){
            ans = n*a;
        }else{
            ans = (n/2)*b;
            if( n%2 ==1 ) ans +=a;
        }
        cout<<ans<<endl;
     }
return 0;
}