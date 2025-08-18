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
        vector<int> v(n + 1);
        map<int, int> mp;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            mp[v[i]] = i;
        }

        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            int val = v[i];
            for (int j = 1; j*val < 2*n; j++)
            {
                if (mp[j] != 0 && mp[j] < i && mp[j] + i == j*val)
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}