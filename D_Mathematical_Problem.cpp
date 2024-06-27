#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int32_t main(){

    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int a[]={169,961,196};
        int m=n-3,p=0;
        if(n==1){cout<<1<<endl;continue;}
 
        if(n==3){
                    cout<<196<<endl<<961<<endl<<169<<endl;
            continue;
        }
        cout<<196;
        for(int i=0;i<m;i++)cout<<0;
        cout<<endl;
        cout<<961;
        for(int i=0;i<m;i++)cout<<0;
        cout<<endl;
        cout<<169;
        for(int i=0;i<m;i++)cout<<0;
        cout<<endl;
        for(int i=0;i<(n-3)/2;i++){
            cout<<9;
            for(int j=0;j<(m-p)/2;j++){
                cout<<0;
            }
            cout<<6;
            for(int j=0;j<(m-p)/2;j++){
                cout<<0;
            }
            cout<<1;
            for(int j=0;j<p;j++){
                cout<<0;
            }
            cout<<endl;
            cout<<1;
            for(int j=0;j<(m-p)/2;j++){
                cout<<0;
            }
            cout<<6;
            for(int j=0;j<(m-p)/2;j++){
                cout<<0;
            }
            cout<<9;
            for(int j=0;j<p;j++){
                cout<<0;
            }
            cout<<endl;
            p+=2;
        }
        
    }
    return 0;
}