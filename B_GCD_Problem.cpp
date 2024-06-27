#include<bits/stdc++.h>
#define int long long 
using namespace std;
int32_t  main (){
     int t;
     cin>>t;
     while(t--){
        int n;
        cin>>n;
        n--;
        int a =2 ;
        int b= n-2;
        while(__gcd(a,b) != 1){
            a++ ;
            b--;
        }
        cout<<a<<" "<<b<<" "<<1<<endl;
     }
return 0;
}