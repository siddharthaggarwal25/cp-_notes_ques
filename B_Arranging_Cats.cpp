#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while(t--){
        int n;
        cin>>n;
        string s1 , s2;
        cin>>s1>>s2;

        int count1_s1=0;
        int count1_s2 =0;

        for(int i=0 ;i< n;i++){
            if( s1[i] == '1' && s2[i]  == '0' ){
                count1_s1++;
            }else if (s1[i] == '0' && s2[i]  == '1'){
                count1_s2++;
            }
        }
        cout<< max(count1_s1 , count1_s2)<<endl;

     }
return 0;
}