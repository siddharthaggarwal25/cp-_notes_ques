#include <bits/stdc++.h>
using namespace std;
#define int long long 
bool check(vector<vector<int>> &bits, int l, int r, int k)
{
    int val = 0;
    for (int i = 0; i < 32; i++)
    {
        if (bits[r][i] - bits[l-1][i] == r - l +1)
            val = val | 1 << i;
    }
    if (val >= k)
        return true;
    return false;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n+1);
        for (int i = 1; i <= n; i++)
            cin >> v[i];
        vector<vector<int>> bits(n + 1, vector<int>(32, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 32; j++)
            {
                if (v[i] & 1 << j)
                {
                    bits[i][j] += bits[i - 1][j] + 1;
                }
                else
                {
                    bits[i][j] += bits[i - 1][j];
                }
            }
        }

        int q;
        cin >> q;
        while (q--)
        {
            int l, k;
            cin >> l >> k;
            int low = l;
            int high = n;
            int ans = -1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (check(bits, l, mid, k))
                {
                    ans = mid;
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}