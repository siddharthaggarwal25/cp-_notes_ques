#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while(t--){
        int n;
        cin>>n;
        int arr[n];
        int one_index;
        int n_index ;

        for(int i=0 ;i< n;i++){
            cin>>arr[i];
            if( arr[i] == 1){
                one_index=i;
            } 
            if( arr[i] == n){
                n_index=i;
            }
        }

        int ans = min( max( one_index ,n_index) +1 ,  n-min( one_index,n_index));
        int ans2 = min( n-1 +2 +one_index -n_index  ,  n-1 +2  -one_index +n_index);
        ans = min( ans , ans2);
        cout<<ans<<endl; 


     }
return 0;
}