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
        int m = 2 * n;
        vector<int> v(m);
        for (int i = 0; i < m; i++)
            cin >> v[i];

        vector<int> prefix(n), suffix(n);
        vector<int> temp(m);
        temp[0] = v[0];
        prefix[0] = v[0];
        suffix[0] = v[m - 1];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + v[i];
        for (int i = 1; i < n; i++)
            suffix[i] = suffix[i - 1] + v[m - 1 - i];

        for (int i = 1; i < m; i++)
        {
            temp[i] = v[i] - v[i - 1];
            if (i - 2 >= 0)
                temp[i] += temp[i - 2];
        }

        vector<int> ans;

        int q = 0;
        for (int i = 0; i < m; i++)
        {
            if (i % 2 == 0)
                q -= v[i];
            else
                q += v[i];
        }
        ans.push_back(q);

        for (int i = 0; i < n - 1; i++)
        {
            int val = suffix[i] - prefix[i] + (temp[m - 2 - i] - temp[i]);
            ans.push_back(val);
        }

        for (auto &it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}