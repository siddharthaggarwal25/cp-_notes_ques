#include<bits/stdc++.h>
using namespace std;
int  main (){
        pair<int , int > ind ;
        for( int i =0 ;i< 5 ;i++){
             for( int j =0 ;j< 5 ;j++){
                  int x ;
                   cin>>x  ;
                   if( x ==1 ){
                       ind.first = i ;
                       ind .second  = j ;
                   }
             }
        }

        int  ans  = abs( ind.first - 2 ) + abs( ind.second - 2);
        cout<<ans<<endl;
return 0;
}