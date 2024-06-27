#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main (){
     int t;
     cin>>t;
     while(t--){
        int n , k ;
        cin>>n >>k;
        int num = n  + n-2;
        int val = num*2;
        if(  k <= val){
            cout<< (k+1)/2<<endl;
        }else{
            cout<< num + k- val<<endl;
        }
      
     }
return 0;
}