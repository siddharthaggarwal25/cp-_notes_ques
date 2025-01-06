#include<bits/stdc++.h>
using namespace std;
int  main (){
      int t ;
      cin>>t ;
      while( t--){
        int n ;
        cin>>n ;
        vector <int > v( n+1);
        for( int i=0 ;i< n ;i++){
            int a ;
            cin>>a ;
            v[a]++;
        }
        int one=0 ;
        int notone =0 ;
        for( auto it : v){
            if( it ==1)one++;
            else if( it != 0 ) notone++;
        }
        cout<< notone +  (( one+1)/2)*2<<endl;
      }
return 0;
}