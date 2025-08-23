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
        vector<int> ans;
        int val = 11;

        while (val <= n)
        {
            if (n % val == 0)
            {
                ans.push_back(n / val);
            }
            if (val > (LLONG_MAX - 1) / 10)
                break;
            val = (val - 1) * 10 + 1;
        }

        cout << ans.size() << endl;
        if (!ans.empty())
        {
            sort(ans.begin(), ans.end());
            for (auto it : ans)
                cout << it << " ";
            cout << endl;
        }
    }
    return 0;
}
