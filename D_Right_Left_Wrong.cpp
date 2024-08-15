#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main (){
     int t ;
     cin>> t ;
     while( t--){
        int n ;
        cin>>n  ;
        vector<int >  arr( n );
        for( int i=0 ;i< n  ;i++){
            cin>>arr[i];
        }
        string s  ;
        cin>>s  ;
        vector<int >prefix( n , 0  );
        prefix[0] = arr[0];
         for( int i =1 ; i< n  ;i++){
            prefix[i]  =  arr[i] + prefix[i-1];
         }
         int low =0 ;
         int high  = n-1  ;
         int ans = 0  ;
         while( low< high ){
            if(  s[low] == 'L' && s[high] == 'R'){
                ans  = ans + prefix[high]  - prefix[low]  + arr[low];
                low++;
                high  -- ;
            }else  if( s[low] == 'R'){
                low++;
            }else{
                high --  ;
            }
         }
         cout<<ans<<endl;
     }
return 0;
}