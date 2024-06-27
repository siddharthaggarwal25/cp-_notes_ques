#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while( t--){
        int x , y ;
        cin>>x>>y ;
        int req = y/2 ;;
        int ones= ( y/2)*7;
        y = y%2 ;
        if( y ){
            req++;
            ones += 11;
        }

        // x = x- ones;
        x= max( 0 , x-ones);
        if( x>0){
            req   = req + ( x)/15;
            x= x%15;
            if( x){
                req++;
            }
        }
        cout<<req<<endl;
     }
return 0;
}