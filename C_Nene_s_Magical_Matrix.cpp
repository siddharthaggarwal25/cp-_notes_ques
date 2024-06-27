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
        vector<vector<int>> v(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                v[i][j] = j + 1;
            }
        }

        for (int j = 0; j < (n - 1); j++)
        {
            for (int i = 0; i < n; i++)
            {
                v[i][j] = i + 1;
            }
        }
        for (int j = 0; j < n; j++)
        {
            v[0][j] = j + 1;
        }
        int ans = 0;
        for (int i = 0; i < (n); i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans += v[i][j];
            }
        }

        cout << ans << " " << 2 * n << endl;
        for (int i = 0; i < n; i++)
        {

            cout << 1 << " ";
            cout << i + 1 << " ";
            for (int k = 0; k < n; k++)
                cout << k + 1 << " ";
            cout << endl;
        }
        for (int j = 0; j < n - 1; j++)
        {
            cout << 2 << " ";
            cout << j + 1 << " ";
            for (int k = 0; k < n; k++)
                cout << k + 1 << " ";
            cout << endl;
        }
        cout << 1 << " ";
        cout << 1 << " ";
        for (int k = 0; k < n; k++)
            cout << k + 1 << " ";
        cout << endl;
    }
    return 0;
}