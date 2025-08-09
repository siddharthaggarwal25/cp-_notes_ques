#include<bits/stdc++.h>
using namespace std;
#define int long long 
bool comp ( pair<int ,int >  a , pair<int , int > b ){
       if( a.first != b.first)return a.first>b.first ;
        return  a.second<b.second;
}
int32_t  main (){
      int t;
      cin>>t ;
      while( t--){
         int n  , k;
         cin>>n>>k ;
         vector<pair<int ,int >> v( n);
         for( int i =0  ;i<n  ;i++){
            cin>>v[i].first;
            if( v[i].first % k != 0 ) v[i].first = v[i].first%k;
            else v[i].first =k ;
            v[i].second =i;
         }
         sort( v.begin(), v.end() , comp );
         for( auto it : v)cout<<it.second+1<<" ";
         cout<<endl;
        
      }
return 0;
}