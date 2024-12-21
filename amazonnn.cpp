#include<bits/stdc++.h>
#include<map>
using namespace std;
int  main (){
     int n;
     cin>>n;
     int sum = 0;

     int a[n+1];
     map<int,int>mp;
     for(int i = 1;i<=n;i++){
        cin>>a[i];
        sum += a[i];
        mp[a[i]]++;
     }

     int ans = INT_MIN;

     for(int i = 1;i<=n;i++){
        int f = (sum-a[i]);
        if(f&1){
            continue;
        }
        if(mp[f/2]>0){
            ans = max(ans,a[i]);
        }
     }
     cout<<ans<<endl;
return 0;
}