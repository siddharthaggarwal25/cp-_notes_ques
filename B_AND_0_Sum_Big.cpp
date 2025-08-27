#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int ans = 1;
        for (int  i = 1; i <= k; i++)
        {
            ans = ans * n % mod;
        }
        cout << ans<<endl;
    }
    return 0;
}