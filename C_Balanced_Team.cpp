#include<bits/stdc++.h>
using namespace std;
int  main (){
     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0 ;i<n ;i++){
        cin>>v[i];
     }
     sort(v.begin() ,v.end());
     int ans =0;
     for(int i=0 ;i< n ;i++){
        int value = v[i] +5;
        int index= upper_bound(v.begin() ,v.end() , value) -v.begin();
        ans = max( ans , index-i);
     }
     cout<<ans<<endl;
return 0;
}