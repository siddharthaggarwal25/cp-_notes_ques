#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main (){
        int t ; 
         cin>>t ;
          while( t--){
               int n , k ; 
               cin>>n>>k ;
                vector< int > v( n );
                 for( int i =0 ;i< n  ;i++) cin>>v[i];
                 
                 if(  k!=1){
                     sort( v.begin() , v.end()  , greater< int> ());
                    int ans = accumulate( v.begin() , v.begin() +k +1 , 0LL  );
                    cout<< ans <<endl; ;
                 }else{
                     
                     int a = *max_element( v.begin() , v.end() -1 ) + v[n-1];
                     int b = *max_element( v.begin() +1 , v.end() ) + v[0];
                     cout<<max( a , b )<<endl;
                      
                 }
          }
return 0;
}