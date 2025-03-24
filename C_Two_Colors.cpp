#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v(m);
        for (int i = 0; i < m; i++)
        {
            cin >> v[i];
        };
        sort(v.begin(), v.end());
        int ans = 0;
            // cout<< v.end() - v.begin()<<endl;
        for (int i = 0; i < n -1; i++)
        {
            int left = i + 1;
            int right = n- i - 1;
            int possible_left = m-  (lower_bound(v.begin(), v.end(), left) - v.begin());
            int possible_right = m- ( lower_bound(v.begin(), v.end(), right) - v.begin());
            ans  += ( possible_left*possible_right) - min( possible_left , possible_right);
        }
        cout << ans << endl;
    }
    return 0;
}