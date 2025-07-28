#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main (){
      int  n,  m ;
      cin>>n>>m;
      vector<int > v( n+1) , pre( n+1);
      pre[0] =0 ;
      for ( int i =1  ;i<=n ;i++){
        cin>>v[i];
        pre[i] = v[i] + pre[i-1];
      }

      int s =0 , e =0 ;
      int ans  =0 ;
      while( e  <= n ){
        int temp = pre[e] - pre[s];
        if( temp <= m){ 
             ans  = max( ans , e -s);
             e++;
        }
        else{
            s++;
        }
      }
      cout<<ans<<endl;

return 0;
}