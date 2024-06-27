#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<vector<int>> dp;
int solve(int ind, int val, vector<int> &arr)
{
    if (val % m == 0) return 1;
    if (ind == arr.size())  return 0;
    if ( val != -1 && dp[ind][val] != -1) return dp[ind][val];
    int nottake = solve(ind + 1, val, arr);
    int take  =0 ;
    if( val == -1)  take  = solve(ind + 1, ( arr[ind]) % m, arr);
    else take  = solve( ind+1  , ( val +  arr[ind])%m , arr); 
    if( val == -1) return take|nottake;
    return dp[ind][val] = take|nottake;
}
int32_t main()
{
    cin >> n >> m;
    if( n>= m ){
        cout<<"YES"<<endl;
        return 0 ;
    }
    vector<int> arr(n);
    dp.assign(n, vector<int>(m + 1, -1));
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int count = solve(0, -1 , arr);
    if (count ==  1)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}