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
        vector<int> odd;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] % 2 == 0)
                ans += v[i];
            else
                odd.push_back(v[i]);
        }
        if (odd.size() == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            sort(odd.begin(), odd.end(), greater<int>());
            for (int i = 0; i < (odd.size()  + 1)/ 2; i++)
            {
                ans += odd[i];
            }
            cout << ans << endl;
        }
    }
    return 0;
}