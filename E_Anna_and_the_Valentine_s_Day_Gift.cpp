#include<bits/stdc++.h>
using namespace std;
int  main (){
     ll n,x,y;
        cin>>n>>x>>y;
        ll a[n];
        map< pair < ll , ll > ,ll >mp;
        ll ans=0;
        for(int i=0 ; i <n ; i++)
        {
            cin>>a[i];
            int aa=a[i]%x;
            int b=a[i]%y;
            ans+=mp[ {(x-aa)%x ,b} ];
            mp[{aa,b}]++;
        }
        cout<<ans;
return 0;
}