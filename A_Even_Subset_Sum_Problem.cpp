#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while(t--){
        int n;
        cin>>n;
        int arr[n];
        int index =-1;
        for(int i=0 ;i<n ;i++){
            cin>>arr[i];
            if( arr[i]%2 ==0){
                index = i;
            }
        }

        if(index >= 0 ){
            cout<<1<<endl;
            cout<<index +1<<endl;
        }else {
            if( n==1){
                cout<<-1<<endl;
            }else{
                cout<<2<<endl;
                cout<<1<<" "<<2<<endl;
            }
        }
     }
return 0;
}