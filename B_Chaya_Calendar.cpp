#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main (){
     int t;
     cin>>t;
     while(t--){
        int n ;
        cin>>n ;
        int arr[n];
        for(int i=0 ;i< n ;i++){
            cin>>arr[i];
        }

        int ans =0 ;

        for(int i=0 ;i< n ;i++){
            if( arr[i] > ans ){
                ans = arr[i];
            }else{
                int count = ans/arr[i] ;
                count++ ;
                
                // while( arr[i]*count <= ans ){
                //     count++;
                // }
                ans = arr[i]*(count);
            }
        }
        cout<<ans<<endl;
     }
return 0;
}