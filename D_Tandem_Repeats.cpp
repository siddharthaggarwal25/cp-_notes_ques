#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while( t--){
        string s ;
        cin>>s;
        int n = s.size();
        int ans=0;
        for( int k=1 ;k<= n/2  ;k++){
            int r=0 , c=0 ;
            for( int i=0 ;i< n- k ;i++){
                if( s[i]== s[i+k] || s[i]=='?' || s[i+k] == '?'){
                    c++;
                }else {
                    c =0 ;
                }

                if( c== k ){
                    r++;
                }

            }
            if( r>0 ) ans = max(ans, k );
        }
        cout<<2*ans<<endl;
     }
return 0;
}