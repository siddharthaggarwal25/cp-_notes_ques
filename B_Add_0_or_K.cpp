#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main (){
        int t;
        cin>>t ;
         while( t--){
              int n ,k;
              cin>>n>>k;
              vector<int>v( n);
              for( int i=0 ;i< n  ;i++){
                 cin>>v[i];

                 int l = v[i]%( k+1);
                 cout<<v[i]+  l*k<<" ";
              }
              cout<<endl;
         }
return 0;
}