#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while(t--){
        int n,m ,k ;
        cin>>n>>m>>k;

        int value =(m-1) + (n-1)*m;

        if( value == k){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

     }
return 0;
}