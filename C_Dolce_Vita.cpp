#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t  main (){
     int t;
     cin>>t;
     while(t--){
        int n , x;
        cin>>n>>x;
        vector <int> v(n);
        for(int i=0 ;i< n ;i++){
            cin>>v[i];
        }
        sort(v.begin() , v.end());
        for(int i=1;i< n;i++){
            v[i] += v[i-1];
        }
        int ans =0;
        for(int i=0 ;i< n;i++){
            if( v[i]> x){
                break;
            }else{
                 ans += (x-v[i])/(i+1) +1;
            }
        }
        cout<<ans <<endl;
     }
return 0;
}