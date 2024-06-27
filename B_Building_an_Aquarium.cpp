#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int low = 0;
        int high = 1e12;
        int mid;
        int ans = 1e12;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            int water = 0;
            for (int i = 0; i < n; i++)
            {
                if (mid - arr[i] > 0)
                {
                    water += mid - arr[i];
                }
            }

            if (water > x)
            {
                high = mid - 1;
            }
            else
            {
                ans = mid;
                low = mid +1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}