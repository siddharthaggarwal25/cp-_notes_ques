#include<bits/stdc++.h>
using namespace std;
int  main (){
     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0 ;i< n;i++){
        cin>>v[i];
     }
     int ans =1;
     int count =1 ;
     for(int i=0 ;i< n-1 ;i++){
        if(v[i] <v[i+1]){
            count ++;
        }else {
            count =1;
        }

        ans = max( ans  , count );
     }
     cout<<ans<<endl;
return 0;
}