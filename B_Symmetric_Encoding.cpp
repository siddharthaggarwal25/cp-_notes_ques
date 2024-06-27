#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while( t--){
        int n ;
        cin>>n;
        string s ;
        cin>>s ;
        vector< int > alpha( 26  , 0 );
        for( int i=0 ;i< n ;i++){
            alpha[s[i]-'a']++;
        }
        string req ="";
        for( int i=0 ;i< 26 ;i++){
            if( alpha[i]){
                req+= 'a' + i ;
            }
        }
        // cout<<req<<endl;
        map< char , char > mp;
        for( int i=0 ;i< req.size() ;i++){
            mp[req[i]]= req[req.size() - i-1 ];
        }
        for( int i=0 ;i< n  ;i++){
            char given = s[i];
            s[i] = mp[s[i]];
        }
        cout<<s<<endl;
         
     }
return 0;
}