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
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        int ans = 0;
        for (int i = 2; i < n; ++i)
        {
            int low = 0;
            int high = i - 1;
            int maxi = max(2*a[i], a[n - 1]);

            while (low < high)
            {
                if (a[low] + a[high] + a[i]> maxi   )
                {
                    ans += (high - low);
                    high--;
                }
                else
                {
                    low++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}