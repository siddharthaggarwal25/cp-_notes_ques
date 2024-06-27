#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i< n;i++){
            cin>>v[i];
        }
        int current_value = v[0] -1;
        int diversity =0;
        for(int i=0 ;i< n ;i++){
              if( v[i] > current_value){
                diversity++;
                current_value =v[i] ;
              }else if( v[i] == current_value){
                diversity++;
                current_value++;
              }
        }
        cout<<diversity<<endl;
     }
return 0;
}