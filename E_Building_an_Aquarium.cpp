#include<bits/stdc++.h>
#define int long long 
using namespace std;
int32_t  main (){
     int t;
     cin>>t;
     while(t--){
        int n , max_water;
        cin>>n>>max_water;
        vector <int> v(n) ;
        for(int i=0 ;i<n;i++){
            cin>>v[i];
        }

        int low =0 ;
        int high = 1e0;
        int height =1;
        while(low<high){
            int water=0;
            int mid = low + (high-low)/2;
            for(int i=0 ;i<n ;i++){
                water += max( mid - v[i] ,0ll);
            }
            if( water <= max_water){
                height = max(height , low );
                low = mid+1;
            }else{
           
                high=mid-1;
            }
        }
        cout<<height+1<<endl;

     }
return 0;
}