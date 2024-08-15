#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t   main (){
     int t ;
     cin>>t ;
     while( t--){
        int n , m , k ;
        cin>>n>>m>>k;
        int g ;
        cin>>g ;
        vector<int > heights( g  );
        for( int i=0 ;i<g  ;i++)cin>>heights[i];
        sort( heights.begin() , heights.end() , greater<int >());
        vector<int > temp ;
        for( int i=0 ;i<n  ;i++){
            for( int j=0 ;j<m  ;j++){
                int x = min ( i , n-1 - i ) + 1;
                int y = min ( j , m-1 -j) +1;
                if( x > min ( k , n-k+1)) x = min ( k , n-k+1);
                if( y > min ( k , m-k+1)) y  = min ( k , m- k+1);
                temp.push_back( x*y);
            }
        }
        int ans  = 0 ;
        sort( temp.begin() , temp.end() , greater<int > ());
        for( int i=0 ;i< g  ;i++){
            ans   = ans  + ( temp[i]*heights[i]);
        }
        cout<<ans<<endl;
     }
return 0;
}