#include <bits/stdc++.h>
using namespace std;
#define int long long

int temp[4] = {2, 3, 5, 7};

int fun(int x)
{
    int ans = x ;
    for (int i = 1; i < 16; i++)
    {
        int cnt = 0;
        int val = 1;
        for (int j = 0; j < 4; j++)
        {
            if (i >> j & 1)
            {
                cnt++;
                val = val * temp[j];
            }
        }
        if (cnt == 1 || cnt ==3 ) ans = ans - (x / val);
        else ans = ans + (x / val);

    }

    return ans;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int ans = fun(r) - fun(l-1);
        cout << ans << endl;
    }
    return 0;
}