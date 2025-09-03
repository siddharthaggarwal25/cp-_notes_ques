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
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int maxi = 0;
        for (int i = 1; i < n; i++)
        {
            if (v[i] < v[i - 1])
            {
                maxi = max(maxi, v[i - 1] - v[i]);
                v[i] = v[i - 1];
            }
        }
        if (maxi > 0)
        {
            int e = log2l(maxi);
            cout << e + 1 << endl;
        }
        else
            cout << 0 << endl;
    }
    return 0;
}