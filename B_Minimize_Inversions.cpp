#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while(t--){
        int n ;
        cin>>n ; 
        vector<pair<int ,int >> a(n);
        for(int i=0 ;i< n ;i++){
            cin>>a[i].first;
        }
        for(int i=0 ;i< n ;i++){
            cin>>a[i].second;
        }


        sort( a.begin() , a.end());

        for(int i=0 ;i< n;i++){
            cout<<a[i].first<<" ";
        }
        cout<<endl;
        for(int i=0 ;i< n;i++){
            cout<<a[i].second<<" ";
        }
        cout<<endl;
     }
return 0;
}