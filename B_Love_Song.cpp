
#include<bits/stdc++.h>
using namespace std;
int  main (){
     int n,q;
     cin>>n>>q;
     string s;
     cin>>s;
     vector<int > v(n+1);
     v[0]=0;
     for(int i=0 ;i< n ;i++){
        v[i+1] = v[i] + s[i] -'a' +1;
     }
     while(q--){
        int l,r;
        cin>>l>>r;
        cout<<v[r] -v[l-1]<<endl;
     }
return 0;
}