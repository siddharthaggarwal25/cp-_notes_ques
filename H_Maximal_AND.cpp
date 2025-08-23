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
        vector<int> bits(31);
        for (int i = 0; i < n; i++)
        {
            int val = v[i];
            for (int j = 0; j < 31; j++)
            {
                if (val & (1 << j))
                    bits[j]++;
            }
        }
        int ans = 0;
        for (int i = 30; i >= 0; i--)
        {
            if (n - bits[i] <= k)
            {
                k = k - (n-bits[i]);
                ans = ans | 1 << i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}