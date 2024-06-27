#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while( t--){
        int n ;
        cin>>n ;
        int arr[n];
        for( int i=0 ;i< n ; i++){
            cin>>arr[i];
        }
        int max  = 0;
        bool check = true;
        for( int i=0 ;i< n  ;i++){
            if( arr[i] <10){
                if( max > arr[i]){
                    check = false;
                    break;
                }
                max = arr[i];
                continue;
            }
            int value  = arr[i];
            int first = arr[i]/10;
            int second = arr[i]%10;
            if( first >= max && second>=max && second>=first){
                max = second ;
                continue;
            }else if( max <= value){
                max= value;
                continue;
            }
            check = false;
            break ;
        }
        if( check )cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
     }
return 0;
}