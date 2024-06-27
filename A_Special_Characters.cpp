#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while(t--){
        int n ;
        cin>>n ;
        if( n%2 == 1){
            cout<<"NO"<<endl;
        }else{
            string s = "";
            for( int i=1 ;i<= n/2 ;i++){
                if( i%2 ==1){
                    s += "AA";
                }else{
                    s +="BB";
                }
            }
            cout<<"YES"<<endl;
            cout<<s<<endl;
        }
     }
return 0;
}