#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main (){
     int n ;
     cin>>n ;
     for(int i= 1 ;i<= n ;i++){
        int boxes = i*i ;
        int ans = (boxes*(boxes-1))/2 ;
        int minus =  2*2*(i-1)*(i-2);
        ans = ans - minus;
        cout<<ans<<endl;
     }
return 0;
}