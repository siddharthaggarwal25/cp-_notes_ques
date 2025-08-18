#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            v[i] += i;
        }
        sort(v.begin() + 1, v.end() );
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] <=  c)
            {
                ans++;
                c -= v[i];
            }
            else
                break;
        }
        cout << ans << endl;
    }
    return 0;
}