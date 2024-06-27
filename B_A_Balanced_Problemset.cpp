#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main (){
     int t;
     cin>>t;
     while(t--){
        int  x , n ;
        cin>>x>>n;
        int ans = 0;
        for(int i=1  ;i*i <= x ;i++){
            if( x%i ==0 ){
                int first= i;
                int second = x/i;
                if( first >= n){
                    ans = max(ans , second  );
                }
                if( second >= n){
                    ans = max( ans , first  );
                }
            }
        }
        cout<<ans<<endl;
     }
return 0;
}