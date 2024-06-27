#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
int maxsum(int arr[], int n)
{
    int temp[n];
    temp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (temp[i - 1] >= 0)
        {
            temp[i] = temp[i - 1] + arr[i];
        }
        else
        {
            temp[i] = arr[i];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, temp[i]);
    }
    return ans;
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            total += arr[i];
        }
        int sum = maxsum(arr, n);
        for (int i = 0; i < k; i++)
        {
            total += sum;
            sum = sum + sum;
            sum = sum % mod;
        }
        total = total % mod;
        if (total < 0)
        {
            cout << total + mod << endl;
            continue;
        }
        cout << total << endl;
    }
    return 0;
}