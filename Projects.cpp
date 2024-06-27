#include <bits/stdc++.h>
using namespace std;
#define int long long
int count(int preindex, int index, vector<array<int, 3>> &a, vector<vector<int>> &dp)
{
    if (index == a.size())
        return 0;
    if (dp[index][preindex + 1] != -1)
        return dp[index][preindex + 1];
    int nottake = count(preindex, index + 1, a, dp);
    int take = 0;
    if (preindex == -1 || a[index][0] > a[preindex][1])
        take = a[index][2] + count(index, index + 1, a, dp);

    return dp[index][preindex + 1] = max(nottake, take);
}
int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<array<int, 3>> a;
    for (int i = 0; i < n; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        a.push_back({x, y, w});
    }
    sort(a.begin(), a.end());
    
    return 0;
}