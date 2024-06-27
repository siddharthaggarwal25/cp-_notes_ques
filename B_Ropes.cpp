#include <bits/stdc++.h>
using namespace std;
#define int long long 
int k;
int  eps=1e-7;
int check_length(int  x,int arr[],int n){
    int pieces=0;
    for(int j=0;j<n;j++){
        pieces+=(int)(arr[j]/x);
    }
    return pieces;
}
int32_t main(){
    int n;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int minimum = arr[0];
    int  low=0,high=minimum,mid;
    int  ans;
    while(low<=high){
        mid=(low+high)/2;
        if(check_length(mid,arr,n)>k){
            low=mid+eps;
        }
        else if(check_length(mid,arr,n)<k){
            high=mid-eps;
        }
        else{
            ans=mid;
            low=mid+eps;
        }
    }
    cout<<ans;
}