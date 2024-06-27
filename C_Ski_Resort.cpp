#include<bits/stdc++.h>
#define int long long 
using namespace std;
int32_t  main (){
     int t;
     cin>>t;
     while(t--){
        int n,k,q;
        cin>>n>>k>>q;
        int arr[n];
        for(int i=0 ;i< n;i++){
            cin>>arr[i];
        }

        int ans =0 ;
        int count =0 ;
        for(int i=0 ;i< n ;i++){
            if( arr[i] <= q){
                count ++;
            }else{
                count=0;
            }
            
            if( count >= k){
                ans += count -k+1;
            }
        }
        cout<<ans<<endl;
     }
return 0;
}