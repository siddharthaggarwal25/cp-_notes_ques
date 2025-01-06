#include<bits/stdc++.h>
using namespace std;

bool compare (const pair<int , int >& a  , const pair<int , int >&b){ 
    int c=a.first+ a.second ;
    int d = b.first + b.second ; 
    if( c != d )return c <d   ;
    else true;
}
int  main (){
     int t ;
     cin>>t ;
     while( t--){
         int n ;
         cin>>n ;
         vector<pair<int , int >> v( n);
         for( int i=0 ;i< n  ;i++)cin>>v[i].first>>v[i].second ;
         sort( v.begin() , v.end() , compare);

         for( int i=0 ;i< n  ;i++){
            cout<<v[i].first<<" "<<v[i].second<<" ";
         }
         cout<<endl;
         
               
     }
return 0;
}