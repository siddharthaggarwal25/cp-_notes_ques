#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int dp[n];
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
                dp[i] = dp[i - 1];
            else
                dp[i] = dp[i - 1] + 1;
        }
        int q;
        cin >> q;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            if (dp[l] == dp[r])
            {
                cout << -1 << " " << -1 << endl;
            }
            else
            {
                // int value = arr[l];
                // for (int i = l ; i <= r; i++)
                // {
                //     if (arr[i] != value)
                //     {
                //         cout << l+1 << " " << i+1 << endl;
                //         break;
                //     }
                // }

                // int max = max_element(arr + l, arr + r + 1) - arr;
                // int min = min_element(arr + l, arr + r + 1) - arr;
                // cout << min + 1 << " " << max + 1 << endl;

                int upper



            }
        }
        cout << endl;
    }
    return 0;
}