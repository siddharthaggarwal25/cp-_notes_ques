#include<bits/stdc++.h>
#define int long long 
using namespace std;
int32_t  main (){
     int n ,m;
     cin>>n>>m;
     int arr[n];
     for(int i=0 ;i< n;i++){
        cin>>arr[i];
     }
     int front[n];
     int back[n];

     front[0]=0;
     back[n-1]=0;

     for(int i=1 ;i< n ;i++){
        if( arr[i] > arr[i-1]){
            front[i]=front[i-1];
        }else{
            front[i] =front[i-1] + arr[i-1] -arr[i];
        }    
     }

     for(int i= n-2 ;i>=0 ;i--){
        if( arr [i] > arr [i+1]){
            back[i] =back[i+1];
        }else{
            back[i] =back[i+1] + arr[i+1]-arr[i];
        }
     }
     while(m--){
        int a , b;
        cin>>a>>b;
        if( a< b){
            cout<< front[b-1] - front[a-1]<<endl;  
        }else{
            cout<< back[b-1] -back[a-1]<<endl;
        }

     }
return 0;
}