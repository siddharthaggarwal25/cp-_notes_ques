#include<bits/stdc++.h>
#define int long long 
using namespace std;
int32_t  main (){
    
     int t;
     cin>>t;
     while(t--){
        string s;
        cin>>s;

        int arr[26];
        for(int i=0 ;i<26 ;i++){
            arr[i]=0;
        }
        for(int i=0 ;i<s.length() ;i++){
            if(i!=s.length() -1){
                if(s[i]== s[i+1]){
                    if(arr[s[i]-'a'] != 2){
                    arr[s[i] -'a'] =1;
                    i++;
                    }
                }else{
                    arr[s[i] -'a'] =2;
                }
            }else{
                arr[s[i]-'a'] =2 ;

            }

        }
        for(int i=0 ;i<26 ;i++){
            if(arr[i] == 2){
                cout<<char('a'+i);
            }
        }
        cout<<endl;

   
     }
return 0;
}