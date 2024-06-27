#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int n;
    cin >> n;
    map<int, int> new_map;
    for (int i = 0; i <= 1e5; i++)
    {
        new_map[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        new_map[k]++;
    }
    int dp[100001];
    dp[0] = 0;
    dp[1] = new_map[1];
    for (int i = 2; i <= 1e5; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + i * new_map[i]);
    }

    cout << dp[100000];

    return 0;
}