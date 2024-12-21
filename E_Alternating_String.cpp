#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t ;
     while( t--){
        int n ;
        cin>>n  ;
        string s  ;
        cin>>s  ;
        if ( n%2 == 0 ){
            vector<int > even ( 26 , 0 );
            vector<int >  odd ( 26 , 0 );
            for( int i=0  ;i< n  ;i ++ ){
                if( i%2 ==0 )even[s[i]-'a']++;
                else odd[s[i]-'a']++;
            }
            int maxi1 = *max_element( even.begin() , even.end());
            int maxi2 = *max_element( odd.begin() , odd.end());
            int op  =  n - maxi1  - maxi2;
            cout<<op<<endl;
        }else{

        }
     }
return 0;
}