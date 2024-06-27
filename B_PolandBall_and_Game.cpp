#include<bits/stdc++.h>
using namespace std;
int  main (){
     int n,m;
     cin>>n>>m;
     set<string> s;
     string str;
     int common =0 ;
     for(int i=0 ;i< n ;i++){
        cin>>str;
        s.insert(str);
     }
     for(int i=0 ;i<m ;i++){
        cin>>str;
        if( s.count(str)){
            common++;
        }else{
            s.insert(str);
        }
     }

     n -= common/2;
     m -=(common+1)/2;
     if(n>m){
        cout<<"YES"<<endl;
     }else{
        cout<<"NO"<<endl;
     }
return 0;
}