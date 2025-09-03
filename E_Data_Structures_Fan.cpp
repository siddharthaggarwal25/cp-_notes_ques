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
        string s;
        cin >> s;
        int ans0 = 0, ans1 = 0;
        vector<int> xorr(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            xorr[i] = xorr[i - 1] ^ v[i];
            if (s[i-1] == '1')
                ans1 = ans1 ^ v[i];
            else
                ans0 = ans0 ^ v[i];
        }
        int q;
        cin >> q;
        while (q--)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                int l, r;
                cin >> l >> r;
                int val = xorr[r] ^ xorr[l - 1];
                ans0 = ans0 ^ val;
                ans1 = ans1 ^ val;
            }
            else
            {

                int e;
                cin >> e;
                if (e == 1)
                {
                    cout << ans1 << " ";
                }
                else
                    cout << ans0 << " ";
            }
        }

        cout << endl;
    }
    return 0;
}