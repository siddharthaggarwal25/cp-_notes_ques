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
        int arr[26];
        for(int i=0 ;i<26 ;i++){
            arr[i]=0;
        }
        for(int i=0 ;i<n ;i++){
            arr[s[i]-'a']++;
        }
        sort(arr ,arr+26);
        while(arr[24]!=0){
            arr[25]--;
            arr[24]--;
            sort(arr,arr+26);
        }
        cout<<s[25]<<endl;      
     }
return 0;
}