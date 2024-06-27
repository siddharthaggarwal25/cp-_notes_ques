#include<bits/stdc++.h>
#define int long long 
using namespace std;
int32_t  main (){
     int t;
     cin>>t;
     while(t--){
        int n , m ;
        cin>>n>>m;
        vector<int> arr(n);
        int val=1;
        for(int i=0  ;i< n ;i++){
            cin>>arr[i];
            val = (val*arr[i])%m;
        } 
        string s ;
        cin>>s;
        int low = 0;
        int high = n-1;
        for(int i=0 ;i< n ;i++){
         
            if( s[i]== 'L'){
                int mod = val %m ;
                cout<< mod<<" ";
                val = val/arr[ low];
                low++ ;
            }else{
                int mod = val%m ;
                cout<< mod<<" ";
                val = val/arr[ high ];
                high-- ;
            }
        }
        cout<< endl;
     }
return 0;
}