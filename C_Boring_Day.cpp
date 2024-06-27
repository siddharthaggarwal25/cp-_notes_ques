#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int low = 0;
        int high = 0;
        int sum = 0;
        int cnt = 0;
        while (high < n)
        {
            sum += arr[high];
            if (low == high && sum > r)
            {
                sum = 0;
                high++;
                low++;
                continue;
            }

            while (low < high && sum > r)
            {
                sum -= arr[low];
                low++;
            }

            if (sum >= l && sum <= r)
            {
                cnt++;
                sum = 0;
                low = high;
            }
            
            high++;
        }
        cout << cnt << endl;
    }
}