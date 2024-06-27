#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while(t--){
        int n;
        cin>>n ;
        if (n< 2020){
            cout<<"NO"<<endl;
        }else{
           int val= n/2020;
            n  = n - (n/2020)*2020;
            if( n<= val){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }

        }
     }
return 0;
}