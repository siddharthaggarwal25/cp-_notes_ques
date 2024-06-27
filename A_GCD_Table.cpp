#include<bits/stdc++.h>
using namespace std;
int  main (){
     int n;
     cin>>n;
     map<int ,int> m;
     for(int i=0 ;i< n*n ;i++){
        int x;
        cin>>x;
        m[x] ++ ;
     }
     int count =0 ;

     for( auto it = m.begin() ; it!= m.end() ;it++ ){
       if( it->second %2 !=0){
        count ++;
        cout<< it->first <<" ";
       }
     }
     if( count != n){
         
     }

return 0;
}