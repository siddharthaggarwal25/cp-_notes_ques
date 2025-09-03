#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 1;

        while (n > 0)
        {
            int d = n % 10;
            n /= 10;

            int ways = (d + 2) * (d + 1) / 2;
            ans *= ways;
        }

        cout << ans << "\n";
    }
    return 0;
}
