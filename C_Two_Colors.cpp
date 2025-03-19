#include<bits/stdc++.h>
using namespace std;
int  main (){
        int t ; 
         cin>>t ;
          while( t--){
              int  n , m ;
               cin>>n>>m ;
                vector<int > v ( m);
                for( int i = 0 ;i< n  ;i++)cin>>v[i];
                sort ( v.begin() , v.end());
                int ans  =0 ;

                for( int i= 0  ;i<n-1  ;i++){
                     int left = i+1;
                     int right = n-i -1 ;
                     int possible_left = *lower_bound( v.begin() , v.end() , left );
                     int possible_right = *lower_bound ( v.begin(), v.end() , right );

                     ans += possible_left*possible_right - min(possible_left , possible_right);
                }
                cout<<ans<<endl;

          }
return 0;
}