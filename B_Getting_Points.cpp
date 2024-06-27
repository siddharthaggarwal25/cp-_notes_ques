#include<bits/stdc++.h>
#define int long long 
using namespace std;
int32_t  main (){
    int tc;
    cin>>tc;
    while(tc--){
        int n,p,l,t;
        cin>>n>>p>>l>>t;
        int days = (n-1)/7 +1;
        int point =0 ;
        int classes=0; 
        int i=1;
        while(point < p &&){
            if( i <= days/2){
                point +=l+ 2*t;
                classes++;
                i++;
            }else if( (i== (days/2 +1)) && (days%2!=0)){
                point +=  l+t;
                classes++;
                i++;
            }else{
                point +=l;
                classes++;
                i++;
            }
        }
        cout<<n-classes<<endl;
    }
return 0;
}