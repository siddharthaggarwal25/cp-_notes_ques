
#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sum = 0;
        vector<int> v(n);
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
            m[v[i]]++;
        }
        int need = (2 * sum) / n;
        int ans = 0;

        if ((2 * sum) % n != 0)
        {
            cout << 0 << endl;
            continue;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                int front = v[i];
                int back = need - v[i];
                if (m[back])
                {
                    ans += m[back];
                }
                if (front == back)
                {
                    ans--;
                }
            }
        }
        cout << ans / 2 << endl;
    }
    return 0;
}