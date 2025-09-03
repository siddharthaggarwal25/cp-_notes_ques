#include <bits/stdc++.h>
using namespace std;


int nextt(int ind, vector<int> &v, map<int, vector<int>> &mp)
{
    auto &vec = mp[v[ind]];
    int indInMP = lower_bound(vec.begin(), vec.end(), ind) - vec.begin();
    int nexId = indInMP + v[ind] - 1;

    if (nexId >= (int)vec.size())
        return -1;
    return vec[nexId];
}

int solve(int ind, vector<int> &v, vector<int> &dp, map<int, vector<int>> &mp)
{
    if (ind >= (int)v.size())
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int next = nextt(ind, v, mp);
    int take = 0;
    if (next != -1)
        take = v[ind] + solve(next + 1, v, dp, mp);

    int nottake = solve(ind + 1, v, dp, mp);

    return dp[ind] = max(take, nottake);
}

int main()
{
   

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> dp(n, -1);
        map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]].push_back(i);
        }

        int ans = solve(0, v, dp, mp);
        cout << ans << "\n";
    }
    return 0;
}
