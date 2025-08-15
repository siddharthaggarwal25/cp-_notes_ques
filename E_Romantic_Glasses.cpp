#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> v[i];
        map<int, int> mp;
        mp[0] = 1;
        int diff = 0;
        bool ans = false;
        for (int i = 1; i <= n; i++)
        {
            if (i & 1)
                diff += v[i];
            else
                diff -= v[i];

            if (mp[diff] != 0)
                ans = true;
            mp[diff] = 1;
        }
        cout << (ans ? "YES\n" : "NO\n" )<< endl;
    }
    return 0;
}