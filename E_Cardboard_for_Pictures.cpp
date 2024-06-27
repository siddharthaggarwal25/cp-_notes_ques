#include<bits/stdc++.h>
#define int long long 
using namespace std;
 int32_t  main(){
    int t;
    cin>>t;
    while(t--){
        int n,c ;
        cin>>n>>c;
        int arr[n];
        for(int i=0 ;i< n ;i++){
            cin>>arr[i];
        };
        int low =1 ;
        int high = 1e9;
        int mid;
        while(low<=high){
            mid =  low + (high -low)/2;
            int total =0;
            for(int i=0 ;i< n ;i++){
                total += (arr[i] + 2*mid)* (arr[i] + 2*mid);
                if(total >c){
                    break;
                }
            }
            if(total == c){
                cout<< mid<<endl;
                break;
            }else if(total < c ){
               low = mid +1 ;
            }else{
                high = mid -1;
            }
        }

    }
    return 0;
 } 