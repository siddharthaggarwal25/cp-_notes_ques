#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t ;
     cin>>t ;
      while( t--){
         int n ;
         cin>>n  ;
         if( n< 102){
            cout<<"NO"<<endl;
         }else{
             
               vector<int > temp ;
               while( n != 0){
                  int a = n%10 ;
                  temp.push_back( a) ;
                  n = n/10 ;
               }
               reverse( temp.begin()  , temp.end());
               
               if( temp[0] == 1 && temp[1]== 0 &&  temp[2] != 0 ){
                    cout<<"YES"<<endl;
               }else{
                cout<<"NO"<<endl;
               }
         }
      }
return 0;
}