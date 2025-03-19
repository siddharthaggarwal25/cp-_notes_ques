#include<bits/stdc++.h>
using namespace std;
int  main (){
      int t;
       cin>>t ;
        while( t--){
              int n , x ;
              int sum =0 ;
            cin>>n>>x ;
            for( int i=0 ;i< n  ;i++){
                 int a ;
                 cin>>a ;
                 sum += a;
            }

            if( sum== n*x)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
return 0;
}