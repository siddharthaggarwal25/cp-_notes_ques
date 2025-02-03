#include<bits/stdc++.h>
using namespace std;

int32_t   main (){
      int t ;
       cin>>t ; 
       while( t--){
          int n ,l , r ;
          cin>>n>>l>>r ;
          vector<int > v( n) , v2( n);
          for( int i=0 ;i< n ;i++)cin>>v[i]  , v2[i] = v[i];
          sort( v.begin()  , v.begin() + r );
          sort( v2.begin() + l-1  , v2.end() );
        long long int value 
          long long int  a = accumulate( v.begin() , v.begin() + r -l +1 ,  );
          long long int  b = accumulate( v2.begin() + l-1 , v2.begin() +r  , 0  );
          cout<< min( a , b)<<endl; 
       
       }
return 0;
}