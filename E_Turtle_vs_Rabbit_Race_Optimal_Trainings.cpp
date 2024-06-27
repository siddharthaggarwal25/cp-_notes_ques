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
        int arr[n + 1];
        arr[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 2; i <= n; i++)
        {
            arr[i] += arr[i - 1];
        }
        int q;
        cin >> q;
        while (q--)
        {
            int l, u;
            cin >> l >> u;
            u = u + arr[l - 1];
            int ans = lower_bound(arr + 1, arr + 1 + n, u) - arr;

            if (arr[ans] - u > u - arr[ans - 1])
                ans--;

            ans = min(n, ans);
            ans = max(l, ans);
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}