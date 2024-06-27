#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while( t--){
         int n , m  ;
         cin>>n>>m;
         int arr[n+1];
         int index ;
         for( int i=1  ;i<= n ;i++){
            cin>>arr[i];
            if( arr[i] ==  m ) index = i;
         }
         
        int l=1  , r = n+1;
        int mid ;
         while( r-l != 1){
            mid  =  ( l+r)/2;
            if( arr[mid] <= m){
                l= mid;
            }else{
                r=mid;
            }
         }
         if( arr[l] == m ){
            cout<<0<<endl;
         }else{
            cout<<1<<endl;
            cout<<l <<" "<<index<<endl;
         }
     }
return 0;
}