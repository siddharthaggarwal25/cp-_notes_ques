#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end(), greater<int>());
        for (int i = 1; i < n; i++)
        {
            v[i] = v[i] + v[i - 1];
        }
        while (q--)
        {
            int value;
            cin >> value;
            int ans = lower_bound(v.begin(), v.end(), value) - v.begin();
            ;
            if (ans == n)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << ans + 1 << endl;
            } 
        }
    }
    return 0;
}