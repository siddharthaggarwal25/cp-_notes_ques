#include<bits/stdc++.h>
using namespace std;
int  main (){
      int t ;
      cin>>t ; 
      while( t--){
          int n ;
          cin>>n  ;
          vector<int> v( n);
          bool ans =  true ;
          for( int i=0 ;i< n ; i++) {
            cin>>v[i] ;
             if( v[i] <= ( n-i-1)*2  || v[i]<= i*2) ans = false;
          }

          if( ans)cout<<"YES"<<endl;
          else cout<<"NO"<<endl;
      }
return 0;
}