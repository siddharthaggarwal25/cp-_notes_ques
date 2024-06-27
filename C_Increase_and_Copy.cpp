#include<bits/stdc++.h>
using namespace std;
int  main (){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int n_root =sqrt(n);
    if( n_root*n_root >= n){
        cout<<2*n_root -2<<endl;
    }else if( (n_root +1)*n_root >=n){
        cout<< 2*n_root -1<<endl;
    }else{
        cout<<2*n_root<<endl;
    }
}
 
return 0;
}