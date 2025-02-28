#include <bits/stdc++.h>
using namespace std;

void solve(int ind, string &s, vector<char> &dp, vector<int> &penalty, int &ans, int k)
{

    if (ind == dp.size())
    {

        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == 'R')
                continue;
            else
            {
                while (i < n && dp[i] == 'B')
                    i++;
                i--;
                count++;
            }
        }

        if (count <= k)
        {
            int temp = 0;
            for (int j = 0; j < n; j++)
            {
                if (s[j] != dp[j])
                    temp = max(temp, penalty[j]);
            }
            ans = min(ans, temp);
        }

        return;
    }

    dp[ind] = 'B';
    solve(ind + 1, s, dp, penalty, ans, k);
    dp[ind] = 'R';
    solve(ind + 1, s, dp, penalty, ans, k);
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> penalty(n);
        for (int i = 0; i < n; i++)  cin >> penalty[i];
        vector<char> dp(n);
        int ans = 1e9;
        solve(0, s, dp, penalty, ans, k);
        cout << ans << endl;
    }

    return 0;
}