#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t ;
     while( t--){
         string s1 ,s2 ,s3 ,s4;
         cin>>s1>>s2;
         s3 = s1;
         s4 = s2;
         s3[0]= s2[0];
         s4[0]= s1[0];
         cout<<s3<<" "<<s4<<endl;
     }
return 0;
}