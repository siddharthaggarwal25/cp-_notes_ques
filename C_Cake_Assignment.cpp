#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{ 
    int t;
    cin >> t;
    while (t--)
    {
        int k, x;
        cin >> k >> x;
        int tot = 1LL << (k + 1);
        int v1 = x, v2 = (tot - x);
        vector<int> ans;
        while (v1 != v2)
        {

            if (v1 < v2)
            {
                ans.push_back(1);
                v1 = v1 * 2;
                v2 = tot - v1;
            }
            else
            {
                ans.push_back(2);
                v2 = v2 * 2;
                v1 = tot - v2;
            }
        }
        cout << ans.size() << "\n";
        reverse(ans.begin(), ans.end());
        for (auto x : ans)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}