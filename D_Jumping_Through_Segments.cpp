#include <bits/stdc++.h>
using namespace std;
#define int long long 
bool check(int mid, vector<pair<int, int>> &v)
{

    int ll = 0;
    int rr = 0;

    for (int i = 0; i < v.size(); i++)
    {
        ll = max(ll - mid, v[i].first);
        rr = min(rr + mid, v[i].second);
        if (ll > rr)
            return false;
    }

    return true;
}
int32_t  main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i].first >> v[i].second;

        int low = 0;
        int high = 1e9;
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (check(mid, v))
            {
                high = mid - 1;
                ans = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}