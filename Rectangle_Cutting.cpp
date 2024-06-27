#include <bits/stdc++.h>
using namespace std;
int f(int a, int b, vector<vector<int>> &dp)
{
    if (a == b)
        return 0;
     if( dp[a][b] !=-1) return dp[a][b];   
    if (a > b)
        return dp[a][b] = 1 + f(a - b, b, dp);
    return  dp[a][b] = 1 + f(a, b - a, dp);
}
int main()
{//wrong

// see gfg
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int>(b+1, -1));
    cout << f(a, b, dp) << endl;
    for( int i=0 ;i<= a  ;i++){
        for( int j=0 ;j<= b  ;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}