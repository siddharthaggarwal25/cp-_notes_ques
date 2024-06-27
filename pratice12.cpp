#include<bits/stdc++.h>
using namespace std;
int  main (){
     vector< int > v  ={1 ,2 ,3 };
     for( int i=0 ;i< ( 1<<3) ;i++){
        for( int j=0 ;j< 3 ;j++){
            if( i & 1<<j ){
                cout<<v[j]<<" ";
            }
        }
        cout<<endl;
     }
return 0;
}