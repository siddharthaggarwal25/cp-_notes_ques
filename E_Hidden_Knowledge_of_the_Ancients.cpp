#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, l, r;
        cin >> n >> k >> l >> r;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int ans = 0;
        int x = 0;
        int y = 0;
        map<int, int> mpx, mpy;

        for (int i = 0; i < n; i++)
        {
            while (x < n && mpx.size() < k)
            {
                mpx[v[x]]++;
                x++;
            }

            while (y < n && mpy.size() <= k)
            {
                mpy[v[y]]++;
                y++;
            }

            if (mpx.size() == k)
            {
                int first_j = x - 1;
                int last_j;

                if (mpy.size() == k + 1)
                    last_j = y - 2;
                else
                    last_j = n - 1;

                int leftLimit = max(first_j, i + l - 1);
                int rightLimit = min(last_j, i + r - 1);

                if (leftLimit <= rightLimit)
                    ans += (rightLimit - leftLimit + 1);
            }

            if (mpx[v[i]] == 1)
                mpx.erase(v[i]);
            else
                mpx[v[i]]--;

            if (mpy[v[i]] == 1)
                mpy.erase(v[i]);
            else
                mpy[v[i]]--;
        }
        cout << ans << endl;
    }
    return 0;
}
