#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>> t;
     while( t--){
        int n  , f, k ;
        cin>>n>>f>>k ; 
        vector< int >  v( n+1);
        for( int i=1  ;i<= n  ;i++)cin>>v[i];
        int value  = v[f];
        sort( v.begin()+1 , v.end());
        reverse( v.begin() +1  , v.end() );
        int low  = 0 ;
        int high = 0 ;
        for( int i=1 ;i<= n  ;i++){
            if( v[i] == value){
                low  = i ;
                while( i<= n &&  v[i] == value ){
                    i++;
                }
                i-- ; 
                high = i ;
                break ;
            }
        }
        if( k < low) cout<<"NO"<<endl;
        else if( k >= high)  cout<<"YES"<<endl;
        else cout<<"MAYBE"<<endl;
     } 
return 0;
}