#include<bits/stdc++.h>
using namespace std;
int  main (){
     int n;
     cin>>n;
     int m;
     cin>>m;
     vector<int> v(n);
     for(int i=0 ;i< n ;i++){
        cin>>v[i];
     }
     int min_value , max_value;
     max_value= *max_element(v.begin() ,v.end());
     max_value = max_value+ m;

     while(m--){
        int ans = min_element(v.begin() , v.end()) - v.begin();
        v[ans]++;
     }
     min_value=*max_element(v.begin() ,v.end());

     cout<<min_value<<" "<<max_value<<endl;
return 0;
}