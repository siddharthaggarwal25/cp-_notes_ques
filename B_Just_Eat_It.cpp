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
        vector<int> v(n);
        int y = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            y += v[i];
        }
        int cur = 0;
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            cur += v[i];
            if (cur < 0)
            {
                cur = 0;
            }
            ans = max(ans, cur);
        }
        cur = 0;
        for (int i = 0; i < n - 1; i++)
        {
            cur += v[i];
            if (cur < 0)
            {
                cur = 0;
            }
            ans = max(ans, cur);
        }

        if (ans >= y)
        {
            cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;
    }
    return 0;
}