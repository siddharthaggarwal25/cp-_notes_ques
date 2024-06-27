#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while(t--){
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=1 ;i<= n ;i++ ){
            cin>>arr[i];
        }
        bool dp[n+1] ={false};
        dp[0]=true;
        for(int i=1 ;i<= n ;i++){

            if( ( i + arr[i] <=n) && dp[i-1]){
                dp[i+arr[i]]=true;
            }
             if ( (i- arr[i] -1>=0)&& dp[i-arr[i] -1]){
                dp[i]=true;
            }
        }




        if( dp[n]){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }


     }
return 0;
}