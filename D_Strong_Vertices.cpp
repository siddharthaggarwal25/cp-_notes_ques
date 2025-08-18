#include<bits/stdc++.h>
using namespace std;
int  main (){
      int t;
       cin>>t ;
       while( t--){ 
          int n ;
          cin>>n ;
          vector<int > a (n) , b(n);
          for( int i=0 ;i<n  ;i++)cin>>a[i];
          for( int i=0 ;i<n  ;i++)cin>>b[i];
          for( int i=0 ;i<n  ;i++)a[i] = a[i] -b[i];

          int maxi  = *max_element( a.begin()  , a.end());

          int cnt = 0 ;
          for( int i=0  ;i<n ;i++)if( a[i] == maxi)cnt++;
          cout<<cnt<<endl;
          for( int i=0 ;i<n  ;i++)if( a[i] == maxi)cout<<i+1<<" ";
          cout<<endl;
       }
return 0;
}