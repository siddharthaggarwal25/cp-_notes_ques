#include<bits/stdc++.h>
using namespace std;
#define int long long 

int dp[1000001][2][2];

int rec(int idx, int done, int turn,  vector<int>&a)
{
   
        if(idx==a.size())return 0;

        int res=-INT_MAX;
        if(dp[idx][done][turn]!=-1)return dp[idx][done][turn];

        if(done==0){
            res=rec(idx+1, 2, 0, a) + a[idx];

        }
        else{
            if(turn==0 && done==2){
                res=max(res, rec(idx+1, 2, 0, a) + a[idx]);
                res=max(res, rec(idx+1, 1, 1, a) - a[idx]);
            }else{
                if(turn){
                    res=max(res, rec(idx+1, 2, 0, a) + a[idx]);
                }else{
                    res=max(res, rec(idx+1, 1, 1, a) - a[idx]);
                }
            }
       }

   
    return dp[idx][done][turn]=res;

}



long long MaximumSum(int N, vector<int> A){
    memset(dp,-1, sizeof(dp));
    return rec(0, 1, 1, A);
}


int32_t main()
{
  

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector< int > a(n);
        memset(dp,-1,sizeof(dp));
       for( int i=0 ;i< n  ;i++){
        cin>>a[i];
       }
        cout<<rec(0, 0, 1, a)<<endl;;
   
    }

}