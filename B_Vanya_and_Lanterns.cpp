#include<bits/stdc++.h>
using namespace std;
int32_t  main (){
     int n ,l;
     cin>>n>>l;
     vector<int> v(n);
     for(int i=0 ;i< n;i++){
        cin>>v[i];
     }

     sort(v.begin() ,v.end());
     int dis=0;
     if( v[0]!=0){
        dis= 2 * v[0];
     }
     if( 2*(l-v[n-1] ) > dis){
        dis= 2*(l- v[n-1]);
     }
     for(int i=0 ;i< n-1 ;i++){
        int ans  = v[i+1] - v[i];
        dis = max(dis, ans );
     }
     if(dis%2==0){
        cout<<dis/2<<endl;
     }else{
cout<<dis/2<<".5"<<endl;
     }
    
return 0;
}