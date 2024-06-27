#include <bits/stdc++.h>
#define int long int
using namespace std;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int totalDiv = 0;
        int sum = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] % x == 0)
            {
                totalDiv++;
            }
            sum += v[i];
        }
        if (totalDiv == n)
        {
            cout << -1 << endl;
        }
        else if (sum % x != 0)
        {
            cout << n << endl;
        }
        else
        {
            int total = sum;
            int first = 0;
            for (int i = 0; i < n; i++)
            {
                total -= v[i];
                if (total % x != 0)
                {
                    first = max(first, n - i - 1);
                    break;
                }
            }
            total = sum;
            int second = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                total -= v[i];
                if (total % x != 0)
                {
                    second = max(second, i);
                    break;
                }
            }

            cout << max(first, second) << endl;
        }
    }
    return 0;
}