#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t   main (){
     int t ;
     cin>>t ;
     while( t--){
         int n ;
         cin>>n ;
         vector<int > v( n+1);
         for( int i=0 ;i< n ; i++)cin>>v[i+1];
         sort( v.begin()+1 , v.end());
         int total =0 ;
         for( int i=0 ;i< n ;i++)total += v[i+1];

         int value  = 2*n* ( v[ n/2 +1]) - total ;
        //  cout<<value<<endl;

        if ( n  <= 2 )cout<<-1<<endl;
         else if( value  < 0  )cout<<0<<endl;
         else cout<< value+1 <<endl;
         
      
     }
return 0;
}