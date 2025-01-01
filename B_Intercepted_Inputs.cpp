#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t ;
     while( t--){
        int n , a ;
        cin>>n ;
        int val  = n-2 ;
        vector<int > v( n+1 , 0 );
        for( int i=0  ;i< n  ;i++){

             cin>>a ;
             v[a]++;
        }
        for( int i=1 ;i<= n ;i++  ){
            if( (val%i ==0 )&&  ( (val== i*i && v[i]>=2)  ||  ( v[val/i] && v[i]) )){
                cout<< i<<" "<<val/i<<endl;
                break ;
            }
        }

     }
return 0;
}