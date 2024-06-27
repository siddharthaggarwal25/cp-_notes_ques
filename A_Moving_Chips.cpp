#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while(t--){
        int n ;
        cin>>n ;
        int arr[n];
        for( int i=0 ;i< n ;i++){
            cin>>arr[i];
        }
        int zero1 =0;
        int zero2 =0;
        int zero3 =0;
        for( int i=0 ;i< n ;i++){
            if( arr[i]==0){
                zero1 ++ ;
            }
        }
        int i=0 ;
        while( arr[i] == 0 ){
            zero2++; ;
            i++;
        }
        int j= n-1;
        while( arr[j]==0){
            zero3++;
            j--;
        }

        cout<< zero1-zero2-zero3<<endl;
     }
return 0;
}