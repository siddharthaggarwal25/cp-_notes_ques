#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int vit, vector<pair<int, string>> &v, vector<vector<int>> &dp)
{
    if (vit == 7) return 0;
    if (ind == v.size()) return 1e9;
    if (dp[ind][vit] != -1)  return dp[ind][vit];
    // not take;
    int nottake = solve(ind + 1, vit, v, dp);
    // take
    int cur = vit;
    for (auto it : v[ind].second)
    {
        if (it == 'A')
            cur = cur | 1;
        else if (it == 'B')
            cur = cur | 2;
        else
            cur = cur | 4;
    }
    int take = v[ind].first + solve(ind + 1, cur, v, dp);
    return dp[ind][vit] = min(take, nottake);
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, string>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    vector<vector<int>> dp(n, vector<int>(8, -1));
    int ans = solve(0, 0, v, dp);
    if (ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}