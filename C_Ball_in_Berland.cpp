#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t  main (){
       int t;
        cin>>t ;
        while( t--){
             int a , b, n ;
              cin>>a>>b>>n ;
              map<int , int > ma, mb ;
              vector <pair<int , int>> v( n);
              for( int i =0 ;i< n ;i++){
                 cin>>v[i].first;
                 ma[v[i].first]++;
              }
              for( int i =0 ;i< n ;i++){
                 cin>>v[i].second;
                 mb[v[i].second]++;
              }

              int ans  =0 ;
              for( int i =0  ;i< n  ;i++){
                  ans  = ans + n - ma[v[i].first] - mb[v[i].second] +1 ;
                  
              }

              cout<<ans/2<<endl;
        }
return 0;
}