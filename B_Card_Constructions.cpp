#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[100000];
int32_t main()
{
    arr[0] = 2;
    for (int i = 1; i < 100000; i++)
    {
        arr[i] = arr[i - 1] + 2 + 3 * i;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        while (n >= 2)
        {
            int *index = lower_bound(arr, arr + 100000, n);
            int value = index - arr;

            if (arr[value] == n)
            {
                ans++;
                n = n - arr[value];
            }
            else
            {
                ans++;
                n = n - arr[value - 1];
            }
        }
        cout << ans << endl;
    }

    return 0;
}