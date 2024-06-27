#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    vector<int> dp(n+1 );
    dp[1] = 0;
    dp[2] = abs(v[2] - v[1]);

    for (int i = 3; i <= n; i++)
    {
        dp[i] =  min(  dp[i-1 ] + abs(v[i] - v[i - 1]), dp[i-2]  + abs(v[i] - v[i - 2]));
    }
    cout<< dp[n]<<endl;

    return 0;
}