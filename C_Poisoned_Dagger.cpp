#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;  
        cin >> n>> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int low = 1;
        int high = 1e18;
        int mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            int ans = 0;
            for (int i = 0; i < n - 1; i++)
            {
                ans += min(mid, arr[i + 1] - arr[i]);
            }
            ans += mid;
            if (ans < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << low << endl;
    }
    return 0;
}