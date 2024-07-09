#include<bits/stdc++.h>
using namespace std;
int  main (){
     int  n ;
     cin>>n ;
     vector<int >a ( n ) , b( n);
     for( int i=0 ;i< n ;i++)cin>>a[i]; 
     for( int i=0 ;i< n ;i++)cin>>b[i]; 
     int maxi  = *max_element( a.begin() , a.end());
     int mini = *min_element( b.begin() , b.end());
     if( maxi >mini){
        cout<<0<<endl;
     }else{
        cout<< mini-maxi +1<<endl;
     }
return 0;
}