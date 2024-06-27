#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while(t--){
        int n ,k;
        cin>>n>>k;
        vector<char> v(n);
    
        for(int i=0 ;i< n;i++){
            cin>>v[i];
        };
        int minWhite=0;
        int ans =0 ;
        for(int i=0 ;i< k ;i++ ){
            if(v[i] == 'W'){
                minWhite++;
            }
        }
        ans=minWhite;
        for(int i= k ;i<n ;i++){
            if( v[i] == 'B'){
                if( v[ i-k] == 'W'){
                    minWhite--;
                }
            }
            else{
                minWhite++;
                if(v[i-k] == 'W'){
                    minWhite--;
                }
            }
            ans = min(ans , minWhite);

        }
        cout<<ans<<endl;
     }
return 0;
}