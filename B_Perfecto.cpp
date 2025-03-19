#include<bits/stdc++.h>
using namespace std;
#define int long long 
bool check(int num) {
     int temp = sqrt ( num);
     if( temp*temp ==  num)return true ;
     return false;
     
}
int32_t   main (){
      int t;
      cin>>t ; 
      while( t--){
         int n ;
          cin>>n  ;
        int netsum =  ( n)*( n+1)/2;
        if( check( netsum))cout<<-1<<endl;
        else{
               int  q= 1 ;
               vector< int > ans ;
               int sum  =0 ;
               for( int i=0 ;i< n ;i++ ){
                   if( check( sum + q)) {
                         ans.push_back( q+1);
                         ans.push_back( q);
                         sum  = sum + 2*q+1 ;
                         q += 2 ;
                         i++;
                   }else{
                    ans.push_back( q);
                    sum = sum + q ;
                    q++;
                   }
               }
               for( auto i : ans )cout<<i <<" ";
               cout<<endl;
        }
      }
return 0;
}