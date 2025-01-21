#include<bits/stdc++.h>
using namespace std;
int  main (){
       int t ; 
       cin>> t; 
        while( t--){ 
             int n , m ;
             cin>>n>>m ;
             vector<pair<int , int >>v( n);
             for( int i=0 ;i< n  ;i++)cin>>v[i].first>>v[i].second;
             int ans  = m*4 ;
             for ( int i =1 ;i<  n  ;i++){
                 int value  =  (( m- v[i].first) + ( m- v[i].second) )*2;
                 ans  = ans  - value  + m*4;
             }
             cout<<ans<<endl;
        }
return 0;
}