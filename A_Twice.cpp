#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t ;
     while( t--){
        int n ;
        cin>>n ;
        vector<int > arr( n+1 , 0);
        for( int i=0 ;i< n  ;i++){
            int a  ;
            cin>>a ;
            arr[a]++;
        }

        int ans  =0 ;
        for( int i= 1  ;i<= n  ;i++){
            ans  += ( arr[i]/2);
        }
        cout<<ans<<endl;
     }
return 0;
}