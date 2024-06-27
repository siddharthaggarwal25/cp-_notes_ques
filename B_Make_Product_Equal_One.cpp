#include<bits/stdc++.h>
using namespace std;
int  main (){
     int n;
     cin>>n;
     int arr[n];
     int positive =0;
     int negative =0 ;
     int zero=0;
     for(int i=0 ;i< n;i++){
        cin>>arr[i];
        if(arr[i] >0){
            positive++;
        }else if( arr[i] <0){
            negative++;
        }else{
            zero++;
        }
     }
    int cost =0;
     for(int i=0 ;i< n ;i++){
        if( arr[i] < 0){
            cost +=  ( arr[i] +1 )*(-1);
        }else if( arr[i]>0){
            cost += arr[i] -1;
        }
     }

     if(negative % 2 !=0){
        if(zero > 0){
        }else{
            cost +=2;
        }
     }
     cost += zero;
     cout<<cost<<endl;

return 0;
}