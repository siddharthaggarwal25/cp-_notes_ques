#include<bits/stdc++.h>

using namespace std;
int  main (){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0 ;i< n ;i++){
            cin>>v[i];
        }
        int low =0 ;
        int high = n-1;
        int left = v[0];
        int right = v[n-1];
        int ans =0 ;
        while(low<high){
            if(left == right){
                ans = max( low + n -high +1 ,ans );
                low++;
                left += v[low];
            }else if( left < right){
                low++;
                left += v[low];
            }else{
                high --;
                right+= v[high];
            }
        }
        cout<<ans<<endl;
    }
     
return 0;
}