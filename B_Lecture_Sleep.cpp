#include <bits/stdc++.h>
#define int long long 
using namespace std;
int32_t main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> t(n);
    int sum_1 = 0;
    int sum_0 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (t[i] == 1)
        {
            sum_1 += a[i];
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (t[i] == 0)
        {
            sum_0 += a[i];
        }
    }
    int value =sum_0;

    for (int i = 1; i + k <= n; i++)
    {
        if (t[i - 1] == 0)
        {
            value -= a[i - 1];
        }
        if (t[i + k - 1] == 0)
        {
            value += a[i + k - 1];
        }
        sum_0 = max(value, sum_0);
    }
    cout << sum_0 + sum_1 << endl;
    return 0;
}