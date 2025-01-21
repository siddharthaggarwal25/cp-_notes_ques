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
        vector<int> v(n);
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            cnt += (v[i] == x);
            sum += v[i];
        }

        if (cnt == n)
            cout << 0 << endl;
        else if (n * x == sum || cnt > 0)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
    return 0;
}