#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while(t--){
        int n ,k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0 ;i< n;i++){
            cin>>v[i];
        }
        bool ans =false;

        if( n==1 && v[0] == k){
            ans=true;
        }else{
            sort(v.begin() ,v.end());
            int i=0;
            int j=1;
            while( i<n && j<n){
                if( v[i] + abs(k) == v[j]){
                    ans =true;
                    break;
                }else if( v[i] + abs(k) < v[j]){
                    i++;
                }else{
                    j++;
                }
            }

        }
        if( ans){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
     }
return 0;
}