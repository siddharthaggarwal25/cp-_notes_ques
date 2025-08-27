#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int ans = 0;
        sort(v.begin(), v.end());
        for (int i = n - 1; i >= 0; i -=2)
        {
            ans += v[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}