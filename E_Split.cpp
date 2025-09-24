#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }
        bool ans = true;
        for (auto &it : mp)
        {
            if (it.second % k != 0)
                ans = false;
            else
                it.second = it.second / k;
        }
        if (!ans)
        {
            cout << 0 << endl;
        }
        else
        {
            int res = 0;
            map<int, int> temp;
            int low = 0;
            int high = 0;

            while (high < n)
            {
                temp[v[high]]++;
                while (temp[v[high]] > mp[v[high]])
                {
                    temp[v[low]]--;
                    low++;
                }
                res += (high - low + 1);
                high++;
            }
            cout << res << endl;
        }
    }
    return 0;
}