#include<bits/stdc++.h>
using namespace std;
int  main (){
     int n, v;
     cin>>n>>v;
     
     if( v >= n-1){
        cout<<n-1<<endl;
     }else{
        int ans =0 ;
        ans += v-1;
        ans += ((n+1-v)*(n-v))/2;
        cout<<ans<<endl;
     }
return 0;
}