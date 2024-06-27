#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t  main (){
     int t;
     cin>>t;
     while(t--){
        int n , m;
        cin>>n>>m;
        vector <int> arr(n);
        vector <int> arr2(m);

        for(int i=0 ;i< n ;i++){
            cin>>arr[i];
        }

        for(int i=0 ; i< m;i++){
            cin>>arr2[i];
        }

        sort(arr.begin() , arr.end());
        sort(arr2.begin() , arr2.end());
        reverse ( arr2.begin() , arr2.end());
        //  for(int i=0 ; i< m;i++){
        //     cout<<arr2[i]<<" ";
        // }
        // cout<<"--";

        int low =0 ;
        int high= n-1;
        int ans = 0 ;

        while( high >= low){
            if( abs(arr[low] - arr2[low] ) > abs( arr[high] -arr2[ high +m -n])) {
                ans += abs(arr[low] - arr2[low] );
                low++;
            }else{
                ans +=abs( arr[high] -arr2[ high +m -n]);
                high--;
            }
        }

        cout<<ans<<endl;

     }
return 0;
}