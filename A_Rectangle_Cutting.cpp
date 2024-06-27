#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t ;
     cin>>t;
     while(t--){
        int a , b ;
        cin>> a>>b;
        if( a>b ) swap(a, b );

        if(( a%2 ==1  && b%2 ==1 ) || (a%2 ==1 && b== 2*a)){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
     }
return 0;
}