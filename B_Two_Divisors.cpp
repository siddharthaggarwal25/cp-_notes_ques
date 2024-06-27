#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main (){
     int t;
     cin>>t;
     while(t--){
        int a , b;
        cin>>a>>b;
      int lcm = (a*b)/(__gcd(a,b));
      if( lcm != b){
        cout<< lcm<<endl;
      }else{
        cout<< (lcm*b)/a<<endl;
      }

     }
return 0;
}