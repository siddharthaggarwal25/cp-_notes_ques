#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while(t--){
        string s;
        cin>>s;

        for(int i=1 ;i<=8 ;i++){
            if(s[1] - '0' == i ){
                continue;
            }else{
                cout<<s[0]<<i<<endl;
            }
        }
        for(int i=0;i<=7 ;i++){
            if(s[0] == 'a'+i){
                continue;
            }else{
                char str = 'a'+i;
                cout<<str<<s[1]<<endl;

            }
        }
     }
return 0;
}