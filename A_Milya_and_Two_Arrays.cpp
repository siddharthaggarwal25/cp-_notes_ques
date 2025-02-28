#include<bits/stdc++.h>
using namespace std;
int  main (){
      int t;
       cin>> t ;
        while( t--){
              int n  , x;
               cin>>n  ;
                set< int> s1 , s2;
                for( int i =0  ;i<n ;i++) cin>>x  , s1.insert( x);
                for( int i =0  ;i<n ;i++) cin>>x  , s2.insert( x);
                if( s1.size()*s2.size() >= 3)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
                 
        }
return 0;
}