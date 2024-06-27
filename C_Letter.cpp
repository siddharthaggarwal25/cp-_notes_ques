#include<bits/stdc++.h>
using namespace std;
int  main (){
     string s;
     cin>>s;
     int upper[s.length()+1] ={0};
     int lower[s.length() +1]= {0};

     for(int i=1 ;i<= s.length() ;i++ ){
        if( s[i-1] <= 'Z'){
            upper[i]= upper[i-1]+1;
            lower[i]= lower[i-1];
        }else{
            lower[i]= lower[i-1] +1;
            upper[i] = upper[i-1];
        }
     }
     int ans = __INT_MAX__;
     for(int i=0 ;i<=s.length() ;i++){
        ans = min(ans , upper[s.length()] - upper[i] + lower[i]- lower[0]);
     }
     cout<<ans;
    
return 0;
}