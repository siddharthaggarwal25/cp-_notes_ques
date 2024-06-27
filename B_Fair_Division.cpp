#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t;
     while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0 ;i<n ;i++){
            cin>>arr[i];
        }
        sort(arr ,arr+n);
        reverse (arr , arr+n);
        int alice=0;
        int bob =0;
        for(int i=0 ;i< n ;i++){
            if(alice == bob){
                alice +=arr[i];
            }else if( alice < bob){
                alice += arr[i];
            }else {
                bob +=arr[i];
            }
        }

        if(alice == bob){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    

     }
return 0;
}