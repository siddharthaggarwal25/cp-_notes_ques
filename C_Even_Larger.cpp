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
        {
            cin >> v[i];
        }

        int ans = 0;

        for (int i = 2; i <= n; i += 2)
        {
            if (i - 1 >= 1 && v[i] < v[i - 1])
            {
                ans = ans + (v[i - 1] - v[i]);
                v[i - 1] = v[i];
            }
            if (i + 1 <= n && v[i] < v[i + 1])
            {
                ans = ans + v[i + 1] - v[i];
                v[i + 1] = v[i];
            }
            if (i - 1 >= 1 && i + 1 <= n &&  v[i] < v[i - 1] + v[i + 1])
            {
                int temp = v[i - 1] + v[i + 1] - v[i];
                ans += temp;
                if (temp < v[i + 1])
                {
                    v[i + 1] = v[i + 1] - temp;
                }
                else
                {
                    v[i + 1] = 0;
                    temp -= v[i + 1];
                    v[i-1] -= temp;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}