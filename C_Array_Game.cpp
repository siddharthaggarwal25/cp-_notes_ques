#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        if (k == 1)
        {
            sort(v.begin(), v.end());
            cout << min(v[0], min(abs(v[0] - v[1]), abs(v[n - 1] - v[n - 2]))) << endl;
        }
        else if (k == 2)
        {
            int ans = 1e9;
            sort(v.begin(), v.end());

            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    ans = min(ans, abs(v[i] - v[j]));
                }
            }
            for( int )
            cout << ans << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}