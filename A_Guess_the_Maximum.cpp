#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t ;
     while( t--){
         int n ;
         cin>>n ;
         vector< int > arr(n);
         for( int i=0 ;i<n  ;i++)cin>>arr[i];
        vector< int > ans ;
        for( int i= 0;i< n-1 ; i++){
            ans.push_back( max( arr[i] , arr[i+1]));
        }
        int mini = *min_element( ans.begin() , ans.end());
        cout<<--mini<<endl;


     }
return 0;
}