#include<bits/stdc++.h>
#define int long long 
using namespace std;
int32_t  main (){
     int n;
     cin>>n;
     int arr[n];
     for(int i=0 ;i< n ;i++){
        cin>>arr[i];
     }
     int m;
     cin>>m;
     int brr[m];
     for(int i=0 ;i< m ;i++){
        cin>>brr[i];
     }
     sort(arr,arr+n);
     sort(brr , brr+m);
     int i=0;
     int j=0;
     int ans =0;
     while( i< n && j< m){
        if( abs(arr[i] - brr[j]) <2){
            i++;
            j++;
            ans++;
        }else if( arr[i] <brr[j]){
            i++;
        }else{
            j++;
        }
     }
     cout<<ans<<endl;
return 0;
}