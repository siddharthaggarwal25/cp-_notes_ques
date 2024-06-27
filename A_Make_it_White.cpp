#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while(t--){
        int n ;
        cin>>n ;
        string s ;
        cin>> s ;

        int low =0 ;
        int high = n-1;
        while( s[low] =='W' ||  s[high]== 'W'){
            if( s[low] == 'W'){
                low++;
            }
            if( s[high] == 'W'){
                high--;
            }
        }
        cout<< high- low +1<<endl;
     }
return 0;
}