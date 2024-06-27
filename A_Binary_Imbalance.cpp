#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int zero=0;
        int one =0;
        for(int i=0 ;i< n ;i++){
            if(s[i]== '0'){
                zero++;
            }else{
                one++;
            }
        }
        if(zero>one){
            cout<<"YES"<<endl;
        }else{
            bool check=false;
            for(int i=0 ;i<n-1 ;i++){
                if( s[i]!=s[i+1]){
                    check=true;
                    break;
                }
            }
            if(check){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
      

       
     }
return 0;
}