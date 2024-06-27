#include<bits/stdc++.h>
using namespace std;
     int arr[100001];
int  main (){
     int n;
     cin>>n;
     arr[0]=0;
     int count =1;
     for(int i=1 ;i<100000 ;i=i+2 ){
        arr[i]=count;
        arr[i+1]=count;
        count++;
     }
     int panels =0;
     int i=1;
     while(panels<n){
        panels += arr[i];
        i++;
     }
     cout<<i<<endl;
return 0;
}