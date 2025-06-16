#include <bits/stdc++.h>
using namespace std;
#define int long long
int check(vector<int> &h, int maxH)
{
    int cnt = 0;
    for (int i = 0; i < h.size(); i++)
    {
        cnt += max(0LL, maxH - h[i]);
    }
    return cnt;
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> h(n);
        for (int i = 0; i < n; i++)
            cin >> h[i];

        int low = 0;
        int high = 1e12;
        int ans = -1;
        while (low <= high)
        {
            int mid =  low  +  (high -low) / 2;
            if (check(h, mid) <= x)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}