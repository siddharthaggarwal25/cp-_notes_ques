#include<bits/stdc++.h>
using namespace std;
#define int long long ;
int  main (){
     int t;
     cin>>t;
     while(t--){
        int n , k ;
        cin>>n>>k;
        int factor =1;
        for(int i=0 ;i< n ;i++){
            int x;
            cin>>x;
            factor *= x;
        }

        if( 2023%factor !=0 ){
               cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            int print = 2023/factor;
            cout<<print<<" ";
            for(int i=0 ;i< k-1 ;i++){
                cout<<1<<" ";
            }
            cout<<endl;
        }

     }
return 0;
}