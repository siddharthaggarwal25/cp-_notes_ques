#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t ;
     while( t--){
        int n ;
        cin>>n  ;
        if( n%2 ==0 ){
            cout<<-1<<endl;
        }else{
            vector<int > temp ;
            for( int i = n ;i>=1  ;i--){
                if( i%2 ==0 )temp.push_back( i);
            }
            for( int i = 1 ;i <= n  ;i ++ ){
                if( i%2 ==1 )temp.push_back( i);
            }

            for ( auto  it  : temp)cout<<it<<" ";
            cout<<endl;
        }
     }
return 0;
}