#include <bits/stdc++.h>
using namespace std;
#define int long long 
int mod =998244353;
int n ;
vector<int > arr ;
int dp[5001][5001];
int colors ( int index , int maxm  , int val){

    if( index == n+1){
        return (max( maxm , ( val +1)/2))%mod ; 
    }

    if( dp[maxm][val] != -1) return dp[maxm][val];
    int take  = colors( index +1 , max( maxm , arr[index] )   , val + arr[index]); 
    int nottake = colors ( index +1  , maxm  , val);
    return (take + nottake)%mod;
}
`
int32_t main()
{

    cin >> n;
    arr.resize( n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    memset( dp , -1 , sizeof(dp));
    cout<< colors( 0 , 0  , 0 )/2<<endl;

    return 0;
}