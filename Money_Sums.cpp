#include <bits/stdc++.h>
using namespace std;
set<int> ans;
vector<vector<int>> dp(100, vector<int>(100* 1000, -1));
void count(int ind, int sum, vector<int> v, vector<vector<int>> &dp)
{
    if (ind == v.size())
        return;
    if (dp[ind][sum] != -1)
        return;
    ans.insert(sum + v[ind]);
    count(ind + 1, sum + v[ind], v, dp);
    count(ind + 1, sum, v, dp);
    dp[ind][sum] = 1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    count(0, 0, v, dp);
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}