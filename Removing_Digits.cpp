#include <bits/stdc++.h>
using namespace std;
int c = 0;
int count(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int ans = 1e8;
    int num = n;
    while (num)
    {
        int digit = num % 10;
        num = num / 10;
        if (digit > 0)
            ans = min(ans, count(n - digit , dp ));
    }
    return dp[n] = 1 + ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << count(n, dp);

    return 0;
}