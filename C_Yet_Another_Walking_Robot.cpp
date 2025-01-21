#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<pair<int, int>, int> mp;
        vector<pair<int, int>> ans;
        int a = 0;
        int b = 0;
        mp[{0, 0}] = 1e6;
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == 'L')
                a++;
            else if (s[i - 1] == 'R')
                a--;
            else if (s[i - 1] == 'U')
                b++;
            else
                b--;
            int past = mp[{a, b}];
            if (past ==  1e6)ans.push_back({0, i});
            else if (past != 0) ans.push_back({past, i});
            

            mp[{a, b}] = i;
        }
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            int ind = 0;
            int mini = 1e9;
            for (int i = 0; i < ans.size(); i++)
            {
                if ((ans[i].second - ans[i].first) + 1 < mini)
                {
                    mini = ans[i].second - ans[i].first + 1;
                    ind = i;
                }
            }
            cout << ans[ind].first + 1 << " " << ans[ind].second << endl;
        }
    }
    return 0;
}