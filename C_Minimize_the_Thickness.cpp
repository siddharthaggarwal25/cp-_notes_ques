#include <bits/stdc++.h>
using namespace std;
long long t, n, a[2010];
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> a[1];
        for (int i = 2; i <= n; i++)
        {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        long long minn = n;
        for (int i = 1; i <= n; i++)
        {
            long long x = i, maxn = i;
            for (int j = i + 1; j <= n; j++)
            {
                if (a[j] - a[x] == a[i])
                    maxn = max(maxn, j - x), x = j;
            }
            if (x == n)
                minn = min(minn, maxn);
        }
        cout << minn << endl;
    }
    return 0;
}
